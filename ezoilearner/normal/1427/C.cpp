#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
typedef long long ll;
typedef pair<int,int> pii;
int n,r;
#define Maxn 100010 
#define cout cerr
#define FR first
#define SE second
int t[Maxn],x[Maxn],y[Maxn];
int dp[Maxn];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(r);rd(n);
	x[0]=y[0]=1;
	int at=-1,res=-inf;
	for(int i=1;i<=n;++i){
		rd(t[i]);rd(x[i]);rd(y[i]);
		dp[i]=-inf;
		while(t[at+1]<=t[i]-r*2){
			at++;
			res=max(res,dp[at]);
		}
		for(int j=at+1;j<i;++j)
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])dp[i]=max(dp[i],dp[j]+1);
		dp[i]=max(dp[i],res+1);
	}
	int ans=0;
	for(int i=0;i<=n;++i)ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}