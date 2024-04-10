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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int d = 20;
int store[100000+1][d];
int n,q,a[100000+2];
LL pre[100000+2];
int main(){
	fastio;
	pre[0]=1;
	rb(i,1,100000)
		pre[i]=pre[i-1]<<1,pre[i]%=(LL)(1e9+7);
	cin>>n>>q;rb(i,1,n) cin>>a[i];
	rb(i,1,n){
	rep(j,d)
		store[i][j]=store[i-1][j];
	rep(j,d){
		if(store[i][j]&&(1&(a[i]>>(j)))){
			a[i]^=store[i][j];
		}
	}
	rep(j,d){
		if(1&(a[i]>>j)){
			store[i][j]=a[i];
			break;
		}
	}
	}	
	while(q--){
		int l,x;
		cin>>l>>x;
		rep(j,d){
			if(store[l][j]&&(1&(x>>j))){
				x^=store[l][j];
			}
		}
		if(x){
			cout<<0<<endl;
		}
		else{
			int sz=0;
			rep(j,d)
				sz+=bool(store[l][j]);
			sz=l-sz;
			cout<<pre[sz]<<endl;
		}
	}
	return 0;
}