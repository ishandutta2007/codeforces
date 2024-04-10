#include <bits/stdc++.h>
#define N 1000500
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

char s[N],t[N];
int n,m,cnt[N],cur[N],o[N],tot;
bool check(int x) {
	long long ret = 0;
	for (int i=1;i<=26;i++)
		ret += max(1LL * x * cnt[i] - cur[i], 0LL);
	return ret <= tot;
}

int main() {
	scanf("%s",s+1); n = strlen(s+1);
	scanf("%s",t+1); m = strlen(t+1);
	
	for (int i=1;i<=n;i++) cur[ s[i]-'a'+1 ]++;
	for (int i=1;i<=m;i++) cnt[ t[i]-'a'+1 ]++;
	for (int i=1;i<=n;i++) if (s[i] == '?') tot++;

	int l = 0, r = n;
	while (l<r) {
		int mid = (l+r+1) >> 1;
		if (check(mid)) l = mid; else r = mid-1;
	}
	
	for (int i=1;i<=26;i++) o[i] = max(1LL * l * cnt[i] - cur[i], 0LL);
	o[26] = 2147483647;
	for (int i=1;i<=n;i++) {
		if (s[i] == '?') {
			for (int j=1;j<=26;j++) if (o[j]) {
				s[i] = 'a'+j-1;
				o[j]--;
				break;
			}
		}
	}
	printf("%s",s+1);
	return 0;
}