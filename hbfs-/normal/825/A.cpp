#include <bits/stdc++.h>
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int n,tmp;
char s[1000500];
int main() {
	n = rd();
	scanf("%s",s+1);
	int ans = 0;
	for (int i=1;i<=n;i++) {
		if (s[i]=='0') ans = ans * 10 + tmp, tmp = 0;
		else tmp++;
	}
	ans = ans * 10 + tmp;
	cout << ans << endl;
	return 0;
}