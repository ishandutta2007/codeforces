#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
char s[maxn],sk[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%s",s+1);
		int n=strlen(s+1),top=0,ans=n;
		for(int i=1;i<=n;i++) {
			if(top==0||s[i]=='A')sk[++top]=s[i];
			else top--,ans-=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}