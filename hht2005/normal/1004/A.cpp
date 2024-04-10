#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[110],n,c[210];
inline int check(int v) {
	int mi=4e9;
	for(int i=1;i<=n;i++)
		mi=min(mi,abs(x[i]-v));
	return mi;
}
signed main() {
	int d,ans=0,cnt=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++) {
		c[++cnt]=x[i]-d;
		c[++cnt]=x[i]+d;
	}
	sort(c+1,c+cnt+1);
	cnt=unique(c+1,c+cnt+1)-c-1;
	for(int i=1;i<=cnt;i++)
		if(check(c[i])==d)ans++;
	cout<<ans<<endl;
	return 0;
}