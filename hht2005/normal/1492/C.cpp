#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char s[maxn],t[maxn];
int n,m,pre[maxn],sa[maxn],ans;
int main() {
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	for(int i=1,j=1;i<=n;i++)
		if(s[i]==t[j])pre[j++]=i;
	for(int i=n,j=m;i>=1;i--)
		if(s[i]==t[j])sa[j--]=i;
	for(int i=1;i<m;i++)
		ans=max(ans,sa[i+1]-pre[i]);
	printf("%d\n",ans);
	return 0;
}