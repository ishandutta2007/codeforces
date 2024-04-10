#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
char s[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,c0,c1,h,sum=0;
		scanf("%d%d%d%d",&n,&c0,&c1,&h);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='0')sum+=min(c0,c1+h);
			else sum+=min(c1,c0+h);
		printf("%d\n",sum);
	}
	return 0;
}