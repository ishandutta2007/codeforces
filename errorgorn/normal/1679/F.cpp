#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))

const int MOD=998244353;

int n,m;
int bm[10];

bool can[1024];
int ans[50005];
int rec[10];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		bm[b]|=1<<a;
	}
	
	can[0]=true;
	rep(x,0,10) for (int y=bm[x];;y=(y-1)&bm[x]){
		can[y|(1<<x)]=can[y];
		if (can[y|(1<<x)]) rec[__builtin_popcount(y)]++;
		if (y==0) break;
	}
	
	for (int x=1;x<10;x+=2) rec[x]=MOD-rec[x];
	
	ans[0]=1;
	rep(x,1,50005){
		rep(y,0,10) if (x-y-1>=0) ans[x]=(ans[x]+ans[x-y-1]*rec[y])%MOD;
	}
	
	cout<<ans[n]<<endl;
}