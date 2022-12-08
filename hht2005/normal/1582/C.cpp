#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char s[N];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&n,s+1);
		int Min=1e9;
		for(int i=0;i<26;i++) {
			int sum=0;
			for(int l=1,r=n;l<=r;l++,r--) {
				int s1=0,s2=0;
				while(l<=n&&s[l]==i+'a')l++,s1++;
				while(r>=1&&s[r]==i+'a')r--,s2++;
				if(l<=r) {
					if(s[l]!=s[r])sum=1e9;
					sum+=max(s1,s2)-min(s1,s2);
				}
			}
			Min=min(Min,sum);
		}
		if(Min>1e8)puts("-1");
		else printf("%d\n",Min);
	}
	return 0;
}