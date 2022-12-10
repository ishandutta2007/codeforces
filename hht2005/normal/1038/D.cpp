#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
inline int read() {
	int x=0,f=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
signed main() {
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1) {
		cout<<a[1]<<endl;
		return 0;
	}
	int sum=0,ans=0;
	for(int i=1;i<=n;i++)sum+=abs(a[i]);
	for(int i=1;i<n;i++)
		ans=max(ans,sum-abs(a[i])-abs(a[i+1])+abs(a[i]-a[i+1]));
	ans=max(ans,sum-abs(a[1])-abs(a[n])+abs(a[1]-a[n]));
	cout<<ans<<endl;
	return 0;
}