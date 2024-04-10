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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=300000+20;
const int TREEN=1<<19;
int segtree[TREEN*2+20],add[TREEN*2+20];//leaf[index]->(bombs in the right (inclusive) - the numbers that are erased int the right(inclusive)) 

vector<pair<int,int> >  v;
int q[MAXN];

int query(int a,int b,int now=1,int l=1,int r=TREEN+1){
	if(r<=b&&l>=a){
		return segtree[now]+add[now];
	}
	if(r<=a||l>=b){
		return INF;
	}		
	int mid=(l+r)>>1;
	return min(query(a,b,now<<1,l,mid),query(a,b,(now<<1)+1,mid,r))+add[now];
}

int Add(int a,int b,int val=1,int now=1,int l=1,int r=TREEN+1){
	if(r<=b&&l>=a){
		add[now]+=val;
		return segtree[now]+add[now];
	}
	if(r<=a||l>=b){
		return segtree[now]+add[now];
	}		
	int mid=(l+r)>>1;
	return (segtree[now]=min(Add(a,b,val,now<<1,l,mid),Add(a,b,val,(now<<1)+1,mid,r)))+add[now];
}
int main(){
	fastio;
	int n;
	cin>>n;
	rb(i,1,n)
	{
		int val;
		cin>>val;
		v.PB(II(val,i));
	}
	sort(ALL(v));
	vector<int> res(1,n);
	int it=n-1;
	rb(i,1,n){
		int bom;
		cin>>bom;
		if(i==n) break;
		Add(1,bom+1);
		while(it>=0){
			int index=v[it].SEC;
			if(query(1,index+1)>=1){
				Add(1,index+1,-1);
			}
			else{
				break;
			}
			it--;
			if(it==-1){
				cout<<endl<<"ERRO!!!"<<endl;
				return 0;
			}
		}
		res.PB(v[it].FIR);
	}
	rep(i,n) cout<<res[i]<<" ";
	return 0;
}