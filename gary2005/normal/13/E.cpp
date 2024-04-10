/*
AuThOr Gwj
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
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=100000+20;
const int MAGIC =1120;
int f[MAGIC+2][MAGIC+2][2],n,m,a[MAXN],tot=0;
void work(int l,int r,int id){
	rl(i,r,l){
		if(a[i]+i>r){
			f[id][i-l+1][0]=1;
			f[id][i-l+1][1]=i;
		}
		else{
			f[id][i-l+1][0]=f[id][i-l+1+a[i]][0]+1;
			f[id][i-l+1][1]=f[id][i-l+1+a[i]][1];
		}
	}
} 
mp dfs(int index){
	int bel=index/MAGIC+1;
	if(index%MAGIC==0) bel--;
	int pos=(bel-1)*MAGIC+1;
	pos=index-pos+1;
	mp res;
	int to=f[bel][pos][1];
	res=II(f[bel][pos][0],f[bel][pos][1]);
	if(to+a[to]>n){
		return res;
	}
	mp tmp=dfs(to+a[to]);
	res.FIR+=tmp.FIR;
	res.SEC=tmp.SEC;
	return res;
}
int main(){
	fastio;
	R2(n,m);
	rb(i,1,n) R(a[i]);
	while((tot)*MAGIC<n)
		tot++;
	rb(i,1,tot)
		work((i-1)*MAGIC+1,min(n,i*MAGIC),i); 
	while(m--){
		int ty;
		R(ty);
		if(ty==1){
			int now;
			R(now);
			mp res=dfs(now);
			cout<<res.SEC<<" "<<res.FIR<<endl; 
		}
		else{
			int x,v;
			R2(x,v);
			a[x]=v;
			int bel=x/MAGIC+1;
			if(x%MAGIC==0) bel--;
			work((bel-1)*MAGIC+1,min(n,bel*MAGIC),bel);
		}	
	}
	return 0;
}