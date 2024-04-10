#include<bits/stdc++.h>
using namespace std;
#define N 200010
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
int T,n,a[N],b[N],len,dp[N];
vector<int> p[N];
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=b[i]=read();
		dp[i]=0;
	}
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=len;++i){
		p[i].clear();
	}
	for(int i=1;i<=n;++i){
		a[i]=lower_bound(b+1,b+len+1,a[i])-b;
		p[a[i]].push_back(i);
	}
	int ans=0;
	for(int i=1;i<=len;++i){
		if(i==1||p[i][0]>p[i-1].back())dp[i]=dp[i-1]+p[i].size();
		else dp[i]=p[i].size()+((upper_bound(p[i-1].begin(),p[i-1].end(),p[i][0])-p[i-1].begin()));
		ans=max(ans,dp[i]+(i==len?0:((int)p[i+1].size()-(int)(lower_bound(p[i+1].begin(),p[i+1].end(),p[i].back())-p[i+1].begin()))));
		if(i<len){
			for(int j=0,k=0;j<(int)p[i].size();++j){
				while(k<(int)p[i+1].size()&&p[i+1][k]<p[i][j])++k;
				ans=max(ans,j+1+(int)p[i+1].size()-k);
			}	
		}
	}
	printf("%d\n",n-ans);
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}