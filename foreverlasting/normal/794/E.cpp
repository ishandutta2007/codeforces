//2018.7.30 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read() {
	res s=0;
	bool w=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return w?-s:s;
}
inline int _max(res x,res y) {
	return x>y?x:y;
}
inline int _min(res x,res y) {
	return x<y?x:y;
}
const int N=3*1e5+10;
int n;
int a[N],ans[N];
int even[N],odd[N];
int main() {
	n=read();
	for (res i=1; i<=n; i++)a[i]=read(),ans[1]=_max(ans[1],a[i]);
	for (res i=1; i<n; i++)even[_min(n-i,i)]=_max(even[_min(n-i,i)],_max(a[i],a[i+1]));
	for (res i=2; i<n; i++)odd[_min(n-i,i-1)]=max(odd[_min(n-i,i-1)],min(a[i],max(a[i-1],a[i+1])));
	for (res i=n/2; i>=1; i--)ans[i<<1]=_max(ans[(i+1)<<1],even[i]);
	for (res i=(n-1)/2; i>=1; i--)ans[i<<1|1]=_max(ans[(i+1)<<1|1],odd[i]);
	for (res i=n; i>=1; i--)printf("%d ",ans[i]);
	return 0;
}