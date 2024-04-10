#include <bits/stdc++.h>
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int n,k,ans,a[1000500];
int main() {
	n = rd(), k = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) {
		while (2*k < a[i]) k<<=1, ans++;
		k = max(a[i], k);
	}
	cout << ans << endl;
	return 0;
}