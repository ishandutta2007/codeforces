#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char s[maxn];
int f[maxn];
int main() {
	int T,n,p,k,x,y;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&p,&k);
		scanf("%s",s+1);
		scanf("%d%d",&x,&y);
		int ans=1e9;
		for(int i=n;i>=p;i--) {
			f[i]=0;
			if(i+k<=n)f[i]=f[i+k];
			if(s[i]=='0')f[i]+=x;
			ans=min(ans,(i-p)*y+f[i]);
		}
		printf("%d\n",ans);
	}
}