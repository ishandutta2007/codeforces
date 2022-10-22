#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#define y1 YYY1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//typedef __int128 l2;
//typedef long long l2;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int> tii;
typedef tuple<db,db,db> tdb;
typedef tuple<ll,ll,ll> tll;
typedef tuple<int,int,int,int> ti4;
typedef tuple<int,int,int,int,int> ti5;
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<db,db,db,db> td4;
typedef vector<vector<ll>> mat;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(a+1,a+1+n,rng)
uniform_int_distribution<> gen(1,100); //gen(rng)
const ll mod=1e9+7,inf=1e18;
const int N=5.5e5+5,M=2.1e6+5;
int n,k,a[2*N],suf[20][N],ans[N];
void solve(int nd,int l,int r,int bit){
	if(a[nd]<=1) return;
	if(a[nd<<1]&&a[nd<<1|1]){
		for(int mask=0;mask<(1<<bit);mask++){
			int n1=nd<<1,n2=nd<<1|1;
			if(mask&(1<<(bit-1))) swap(n1,n2);
			for(int bit2=bit-2;bit2>=0;bit2--){
				if(mask&(1<<bit2)){
					if(a[n1<<1]) n1<<=1;
					else n1=n1<<1|1;
					if(a[n2<<1|1]) n2=n2<<1|1;
					else n2<<=1;
				} else{
					if(a[n1<<1|1]) n1=n1<<1|1;
					else n1<<=1;
					if(a[n2<<1]) n2<<=1;
					else n2=n2<<1|1;
				}
			}
			suf[bit-1][mask]=min(suf[bit-1][mask],(n2^mask)-(n1^mask));
		}
	}
	int m=(l+r)>>1;
	solve(nd<<1,l,m,bit-1); solve(nd<<1|1,m+1,r,bit-1);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>k;
	for(int v,i=1;i<=n;i++){
		cin>>v;
		v+=1<<k;
		while(v){
			a[v]++;
			v/=2;
		}
	}
	for(int i=0;i<(1<<k);i++) ans[i]=1e9;
	for(int bit=0;bit<k;bit++) for(int i=0;i<(1<<k);i++) suf[bit][i]=1e9;
	solve(1,0,(1<<k)-1,k);
	for(int i=0;i<(1<<k);i++){
		int j=i;
		for(int bit=k-1;bit>=0;bit--){
			ans[i]=min(ans[i],suf[bit][j]);
			if(j&(1<<bit)) j^=1<<bit;
		}
		cout<<ans[i]<<" ";
	}
	return 0;
}