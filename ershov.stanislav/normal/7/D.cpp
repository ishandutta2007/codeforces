#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define N 5000010
int d[N][2], r[N], ans, n;
char s[N];
int main() {
	gets(s);
	n=strlen(s);
	for (int t=0; t<2; t++) {
		int l=0, r=-1, j;
		for (int i=0; i<n; i++) {
			if (i>r) j=1; else j=min(r-i+t, d[l+r-i+t][t])+1;
			while (i+j-t<n&&i-j>=0&&s[i-j]==s[i+j-t])j++;
			j--;
			d[i][t]=j;
			if (i+j-t>r) r=i+j-t, l=i-j;
		}
	}
	for (int i=0; i<n; i++) if (d[(i+1)>>1][i&1]==(i+1)>>1) r[i]=r[(i-1)/2]+1, ans+=r[i];
	cout << ans;
	return 0;
}