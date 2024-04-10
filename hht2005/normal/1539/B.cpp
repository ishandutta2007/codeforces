#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char s[maxn];
int t[maxn][26];
int main() {
	int n,q,l,r;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) {
		memcpy(t[i],t[i-1],sizeof(t[i]));
		t[i][s[i]-'a']++;
	}
	while(q--) {
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int i=0;i<26;i++)
			ans+=(t[r][i]-t[l-1][i])*(i+1);
		printf("%d\n",ans);
	}
	return 0;
}