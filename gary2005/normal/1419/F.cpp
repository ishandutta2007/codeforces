/*
{By GWj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1000+10;
int n;
struct DSU{
	int fa[MAXN];
	void inti(){
		rb(i,1,n) fa[i]=i;
	}
	int root(int x){
		if(fa[x]==x) return x;
		return fa[x]=root(fa[x]);
	}
	void merge(int u,int v){
		fa[root(u)]=root(v);
	}
}dsu;
int dist(mp A,mp B)
{
	if(A.FIR==B.FIR){
		return abs(A.SEC-B.SEC);
	}
	if(A.SEC==B.SEC){
		return abs(A.FIR-B.FIR);
	}
	return INF+INF;
}
mp point[MAXN]; 
int belong[MAXN],idd[MAXN],id[MAXN][MAXN][2];
int cou[MAXN*MAXN*2];
map<mp,int> app;
int cnt_point=0;
bool check(int x){
	dsu.inti();
	memset(cou,0,sizeof(cou));
	memset(belong,0,sizeof(belong));
	fill(idd,idd+MAXN,-1);
	rb(i,1,n)
		rb(j,1,n){
			if(dist(point[i],point[j])<=x){
				dsu.merge(i,j);
			}
		}
	int cnt=0;
	rb(i,1,n)
		if(dsu.root(i)==i) cnt++,idd[i]=cnt-1;
	if(cnt==1) return true;
	if(cnt>4) return false;
	if(cnt==2){
		rb(i,1,n)
			rb(j,1,n)
				if(dsu.root(i)!=dsu.root(j))
				if(dist(point[i],point[j])<=x+x){
					return true;
				}
	}
	int cntt=0;
	rb(i,1,n)
		rb(j,1,n){
			if(dsu.root(i)!=dsu.root(j)){
				if(dist(point[i],point[j])==INF+INF){
					if(max(abs(point[i].FIR-point[j].FIR),abs(point[i].SEC-point[j].SEC))<=x){
						cou[id[i][j][0]]|=1<<idd[dsu.root(i)];
						cou[id[i][j][1]]|=1<<idd[dsu.root(j)];
						cou[id[i][j][0]]|=1<<idd[dsu.root(j)];
						cou[id[i][j][1]]|=1<<idd[dsu.root(i)];
					}
				}
			}
		}
	rb(i,1,cnt_point){
		if(cou[i]==(1<<cnt)-1){
			return true;
		}
	}
	return false;
}
int main(){
	fastio;
	R(n);
	rb(i,1,n) R2(point[i].FIR,point[i].SEC);
	rb(i,1,n){
		rb(j,1,n){
			int x,y;
			x=point[i].FIR;
			y=point[j].SEC;
			app[II(x,y)]=(app[II(x,y)]? app[II(x,y)]:++cnt_point);
			id[i][j][0]=app[II(x,y)];
			x=point[j].FIR;
			y=point[i].SEC;
			app[II(x,y)]=(app[II(x,y)]? app[II(x,y)]:++cnt_point);
			id[i][j][1]=app[II(x,y)];
			
		}
	}
//	check(1);
//	return 0;
	int l=1,r=2000000001;
	while(l<r){
		int mid=((LL)l+(LL)r)>>1;
		if(check(mid)){
			r=mid;
		}
		else{
			l=mid+1;
		} 
	}
	if(l==2000000001){
		l=-1;
	}
	cout<<l<<endl;
	return 0;
}