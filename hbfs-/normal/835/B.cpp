#include <bits/stdc++.h>
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

int k,cnt[100],tot,n,ans;
char s[1000500];

int main() {
	int k = rd();
	scanf("%s",s+1);
	n = strlen(s+1);
	for (int i=1;i<=n;i++) {
		cnt[ s[i]-'0' ]++;
		tot += s[i]-'0';
	}
	for (int i=0;i<=8;i++) {
		if (tot < k) {
			int cur = (k-tot) / (9-i);
			if ((9-i)*cur+tot < k) cur++;
			
			cur = min(cur, cnt[i]);
			ans += cur;
			tot += cur * (9-i);
		}
	}
	cout << ans << endl;
	
	return 0;
}