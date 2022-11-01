#include <bits/stdc++.h>
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int n,a[1000000],ans1,ans2,tp;
int main() {
	n = rd();
	for (int i=1;i<=n;i++) {
		int x = rd();
		for (int _=1;_<=x/2;_++) ans1 += rd();
		if (x&1) a[++tp] = rd();
		for (int _=1;_<=x/2;_++) ans2 += rd();
	}
	sort(a+1,a+tp+1,greater<int>() );
	for (int _=1;_<=tp;_++) if (_&1) ans1 += a[_]; else ans2 += a[_];
	cout << ans1 << " " << ans2 << endl;
	return 0;
}