#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
char s[2010][2010];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m,p=1,H=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++) {
				if(s[i][j]=='#')p=p*2%mod;
				else H=0;
			}
		}
		printf("%d\n",(p-H+mod)%mod);
	}
}