#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,dp[N],l[N],r[N],a[N],cnt[N];
int w[N];
vector<int> vec[N];
int main(){
	n=read();
	memset(l,0x3f,sizeof(l));
	for(int i=1;i<=n;++i){
		a[i]=read();
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
	}
	for(int i=n;i>=1;--i){
		++cnt[a[i]];
		dp[i]=max(dp[i+1],cnt[a[i]]);
		if(i==l[a[i]]){
			dp[i]=max(dp[i],dp[r[a[i]]+1]+cnt[a[i]]);
		}
	}
	printf("%d\n",n-dp[1]);
	return 0;
}