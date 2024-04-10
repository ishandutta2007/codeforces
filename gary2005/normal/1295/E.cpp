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
#define int LL
using namespace std;
const int INF=1000000000;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int treen;
LL seg_tree[8*200000+10],add_tree[8*200000+10];
LL add(int now,int l,int r,int a,int b,LL val){
	if(a>=b) return 0;
	if(r<=b&&l>=a) {
		add_tree[now]+=val;
		return seg_tree[now]+add_tree[now]; 
	}
	if(r<=a||l>=b){
		return seg_tree[now]+add_tree[now]; 
	}
	int mid=(l+r)>>1;
	seg_tree[now]=min(add(now<<1,l,mid,a,b,val),add((now<<1)+1,mid,r,a,b,val));
	return seg_tree[now]+add_tree[now];
}
LL query(int now,int l,int r,int a,int b){
	if(r<=b&&l>=a) {
		return seg_tree[now]+add_tree[now]; 
	}
	if(r<=a||l>=b){
		return INF; 
	}
	int mid=(l+r)>>1;
	return min(query(now<<1,l,mid,a,b),query((now<<1)+1,mid,r,a,b))+add_tree[now];
}
int app[2000000+3];
signed main(){
	fastio;
	int n;
	LL p[200000+3],a[200000+3];
	cin>>n;
	treen=1<<(LL)(ceil(log2(double(n))));
//	cout<<treen<<endl;
	rb(i,1,n)
		cin>>p[i],app[p[i]]=i;
	rb(i,1,n){
		cin>>a[i];
//		if(n==200)
	}
	
	//i in
	LL res=min((p[1]==1? 0:a[1]),(p[n]==n? 0:a[n]));
	LL TMP=0;
	rb(i,1,n-1){
		if(p[i]!=1){
			TMP+=a[i]; 
		}
		add(1,1,treen+1,i,i+1,TMP);
//		if(n==200000&&TMP<0) cout<<" "<<TMP;
	} //if(n==200000) cout<<endl;
	TMP=0;
	rl(i,n-1,1){
		if(p[i+1]==1){
			TMP+=a[i+1];
		}
		add(1,1,treen+1,i,i+1,TMP);
	}
	res=min(res,query(1,1,treen+1,1,n));
	rb(i,2,n-1){
		//i
		if(app[i]!=n){
			
			add(1,1,treen+1,app[i],n,-a[app[i]]); 
		}
		
		if(app[i]!=1)
		add(1,1,treen+1,1,app[i],a[app[i]]);
		res=min(res,query(1,1,treen+1,1,n));
	}
	cout<<res<<endl;
	return 0;
}