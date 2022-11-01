#include <bits/stdc++.h>
#define N 1000050

using namespace std;
inline int rd() { int r; scanf("%d",&r); return r; }
int n,k,ans,l,h,p;
char s[N];
int main() {
	scanf("%s",s+1); l = strlen(s+1);
	k = rd();
	h = 1;
	for (int i=1;i<l;i++) 
		if (s[i] == '0') ans++ , h++; else break;
	for (int i=1;i<=l;i++) if (s[i] == '0') p = 1;
	int i = l;
	while (k && i>=h-1) {
		if (s[i] == '0')
			k--;
		else
			ans++;
		i--;
	}
	if (k) ans = N; 
	if (p) ans = min(ans,l-1);
	printf("%d\n",ans);
	return 0;
}