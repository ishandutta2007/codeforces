/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,k;
string s;
const int MAXN=600000+20;
vector<int> cover[300000+1];
struct GARYDSU{
	int fa[MAXN],val[MAXN],size[MAXN],fixed[MAXN]={0};
	void init(){
		rep(i,MAXN)
			fa[i]=i,val[i]=bool(i<=k),size[i]=1;
	}
	int query(int x){
		if(fa[x]==x) return x;
		return fa[x]=query(fa[x]);
	}
	void merge(int u,int v){
		int fu,fv;
		fu=query(u);
		fv=query(v);
		if(fu==fv) return;
		//merge v to u
		size[fu]+=size[fv];
		val[fu]+=val[fv];
		fixed[fu]|=fixed[fv];
		fa[fv]=fu;
	}
	int re(int a){
		return a>k? a-k:a+k;
	}
	bool same_root(int u,int v){
//		cout<<u<<" "<<v<<endl;
		return query(u)==query(v);
	}
	int con(int u){
		int A,B;
		A=val[query(u)];
		B=val[query(re(u))];
		if(fixed[query(u)]){
			B=INF;
		}
		if(fixed[query(re(u))]){
			A=INF;
		}
//		cout<<u <<" "<<A<<" "<<re(u)<<" "<<B<<endl;
		return min(A,B);
	}
}dsu;
int main(){
	fastio;
	cin>>n>>k>>s;
	rb(i,1,k){
		int c;
		cin>>c;
		rep(j,c){
			int a;
			cin>>a;
			cover[a].PB(i);
		}
	}
	dsu.init();
//	cout<<dsu.fa[1]<<endl;
	int ans=0;
	rep(i,n){
		if(s[i]=='1'){//twice or zero!!
			if(cover[i+1].size()==0) ;
			else
			if(cover[i+1].size()==1){
				ans-=dsu.con(cover[i+1][0]);
//				cout<<"FIX"<<dsu.query(cover[i+1][0]+k)<<endl; 
				dsu.fixed[dsu.query(cover[i+1][0]+k)]=1;
				ans+=dsu.con(cover[i+1][0]);
			}
			else
			if(!dsu.same_root(cover[i+1][0],cover[i+1][1])){
				ans-=dsu.con(cover[i+1][0]+k)+dsu.con(cover[i+1][1]+k);
				dsu.merge(cover[i+1][0]+k,cover[i+1][1]+k);
				dsu.merge(cover[i+1][0],cover[i+1][1]);
				ans+=dsu.con(cover[i+1][0]);
//				cout<<cover[i+1][0]<<endl;
			}
		} 
		else{
//			cout<<"SI"<<cover[i+1].size()<<endl;
			if(cover[i+1].size()==1){
				//this must be chosen
				ans-=dsu.con(cover[i+1][0]);
//				cout<<"Here"<<dsu.query(cover[i+1][0])<<endl;
				dsu.fixed[dsu.query(cover[i+1][0])]=1;
				ans+=dsu.val[dsu.query(cover[i+1][0])];
			}
			else{
				if(!dsu.same_root(cover[i+1][0],cover[i+1][1]+k)){
					ans-=dsu.con(cover[i+1][0]+k)+dsu.con(cover[i+1][1]+k);
					dsu.merge(cover[i+1][0],cover[i+1][1]+k);
					dsu.merge(cover[i+1][0]+k,cover[i+1][1]);
					ans+=dsu.con(cover[i+1][0]+k);
				}
			}
		} 
		cout<<ans<<endl;
	}
//	cout<<dsu.fixed[5+k]<<endl;
	return 0;
}