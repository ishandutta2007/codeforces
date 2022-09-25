#include<bits/stdc++.h>
using namespace std;
#define N 2200100
typedef long long ll;
const int m=21;
int n,a[N];
struct Data{
	int mx,se;
	Data(int _a=0,int _b=0){mx=_a,se=_b;}
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		c.mx=max(a.mx,b.mx);
		c.se=a.mx==c.mx?max(a.se,b.mx):max(a.mx,b.se);
		return c;
	}
	Data operator += (const Data &a){
		return *this=*this+a;
	}
}dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		dp[a[i]]+=Data(i,0);
	}
	for(int j=0;j<m;++j){
		for(int i=0;i<(1<<m);++i){
			if(i>>j&1){
				dp[i^(1<<j)]+=dp[i];
			}
		}
	}
	int ans=0;
	for(int i=n-2;i>=1;--i){
		int g=0;
		for(int j=m-1;j>=0;--j){
			if(!(a[i]>>j&1)){
				if(dp[g|(1<<j)].se>i){
					g|=1<<j;
				}	
			}
		}
		ans=max(ans,g|a[i]);
	}
	cout<<ans<<'\n';
	return 0;
}