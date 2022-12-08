#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
int pre[maxn][2];
int main() {
	int n;
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++) {
		pre[i+1][0]=pre[i][0];
		pre[i+1][1]=pre[i][1];
		if(s[i]!='?')pre[i+1][(s[i]&1)^1]=i+1;
	}
	for(int i=1;i<=n;i++) {
		int now=0,ans=0;
		while(now+i<=n) {
			if(pre[now+i][0]==pre[now][0]||pre[now+i][1]==pre[now][1])now+=i,ans++;
			else now=pre[now+i][pre[now+i][0]>pre[now+i][1]];
		}
		printf("%d ",ans);
	}
	return 0;
}