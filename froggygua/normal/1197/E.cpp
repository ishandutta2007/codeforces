#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
#define N 400020
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
int n,b[N],len;
vector<int> vec[N];
struct doll{
	int l,r;
	bool operator <(const doll b)const{
		return r<b.r;
	}
}a[N];
int dp[N],mn[N],ans,qwq,mxl;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].r=read();
		a[i].l=read();
		b[++len]=a[i].l;
		b[++len]=a[i].r;
	}
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		a[i].l=lower_bound(b+1,b+len+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+len+1,a[i].r)-b;
		mxl=max(mxl,a[i].l);
		vec[a[i].r].push_back(i);
	}
	dp[0]=1; 
	for(int i=1;i<=len;++i){
		mn[i]=0;
		for(auto u:vec[i]){
			int d=mn[a[u].l]+b[a[u].l]-b[i];
			if(d==mn[i]){
				dp[i]=(dp[i]+dp[a[u].l])%mod;
			}
			else if(d<mn[i]){
				mn[i]=d;
				dp[i]=dp[a[u].l];
			}
		}
		if(mn[i]>mn[i-1]){
			mn[i]=mn[i-1];
			dp[i]=dp[i-1];
		}
		else if(mn[i]==mn[i-1]){
			dp[i]=(dp[i]+dp[i-1])%mod;
		}
	}
	qwq=0x3f3f3f3f;
	for(int i=mxl+1;i<=len;++i){
		qwq=min(qwq,mn[i]+b[i]);
	}
	for(int i=mxl+1;i<=len;++i){
		if(mn[i]+b[i]==qwq){
			ans=(ans+dp[i])%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}