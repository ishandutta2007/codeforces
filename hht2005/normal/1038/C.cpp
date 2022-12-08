#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010],b[100010];
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
	for(int i=1;i<=n;i++)b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int ans=0,i=n,j=n,t=1;
	while(i||j) {
		if(t==1) {
			if(i&&(!j||a[i]>b[j]))ans+=a[i--];
			else j--;
		} else {
			if(j&&(!i||b[j]>a[i]))ans-=b[j--];
			else i--;
		}
		t^=1;
	}
	cout<<ans<<endl;
	return 0;
}