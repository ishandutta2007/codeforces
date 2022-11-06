#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
ll n,k,nb,no[110][110],ni[1010],dp[10010][60],ansn;
struct Info{ll nu,co;}b[110];
ll po(ll x,ll y){ll z=1;while (y){if (y%2)z=x*z%mo;x=x*x%mo;y/=2;}return z;}
void dfs(int x,ll y,ll z){
	if (x>nb){ansn=(ansn+y*z)%mo;return ;}
	for (int i=0;i<=b[x].co;i++){
		dfs(x+1,y,z*no[x][i]%mo);
		y=y*b[x].nu%mo;
	}
}
int main(){
	cin>>n>>k;
	ll nn=n;
	for (int i=1;i<=1000;i++) ni[i]=po(i,mo-2);
	for (ll i=2;i*i<=n;i++)
		if (nn%i==0){b[++nb].nu=i;while (nn%i==0){nn/=i;b[nb].co++;}}
	if (nn!=1){b[++nb].nu=nn;b[nb].co=1;}
	for (int i=1;i<=nb;i++){
		for (int j=0;j<=k;j++)
			for (int l=0;l<=b[i].co;l++) dp[j][l]=0;
		dp[0][b[i].co]=1;
		for (int j=0;j<k;j++)
			for (int l=0;l<=b[i].co;l++)
				for (int p=0;p<=l;p++)dp[j+1][p]=(dp[j+1][p]+dp[j][l]*ni[l+1])%mo;
		for (int l=0;l<=b[i].co;l++)no[i][l]=dp[k][l];
	}
	dfs(1,1,1);
	cout<<ansn<<endl;
	return 0;
}