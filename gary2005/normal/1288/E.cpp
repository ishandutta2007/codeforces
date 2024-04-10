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
int n,m,res[300000+1][2],app[300000+1],tree[2400000+1],treen;
int a[300000+1];
void change(int x,int gg){
	x+=treen-1;
	tree[x]=gg;
	x>>=1;
	while(x){
		tree[x]=tree[x<<1]+tree[(x<<1)+1];
		x>>=1;
	}
}
int query(int a,int b,int now=1,int l=1,int r=treen+1){
	if(l>=a&&r<=b){
		return tree[now];
	}
	if(r<=a||l>=b){
		return 0;
	}
	int mid=(l+r)>>1;
	return query(a,b,now<<1,l,mid)+query(a,b,(now<<1)+1,mid,r);
}
int main(){
	fastio;
	cin>>n>>m;
	treen=1<<int(ceil(log2(double(n))));
	rb(i,1,n) res[i][0]=res[i][1]=i;
	rb(i,1,m) cin>>a[i],res[a[i]][0]=1;
	rb(i,1,m){
		if(app[a[i]]) continue;
		app[a[i]]=1;
		change(a[i],1);
		res[a[i]][1]=max(res[a[i]][1],a[i]+query(a[i]+1,n+1));
	}
	rb(i,1,n){
		if(!app[i])
			res[i][1]=max(res[i][1],i+query(i+1,n+1));
	}
	treen=1<<int(ceil(log2(double(m))));
	memset(tree,0,sizeof(tree));
	rb(i,1,n)
		app[i]=0;
	rb(i,1,m){
		if(app[a[i]]){
			res[a[i]][1]=max(res[a[i]][1],1+query(app[a[i]]+1,i));
		}
		change(app[a[i]],0);
		change(i,1);
		app[a[i]]=i;
	}
	rb(i,1,n){
		if(app[i])
		res[i][1]=max(res[i][1],1+query(app[i]+1,m+1));
	}
	rb(i,1,n) cout<<res[i][0]<<" "<<res[i][1]<<endl;
	return 0;
}