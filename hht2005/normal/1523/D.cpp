#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,mod=998244353;
char s[maxn][65];
int f[1<<15],t[15],c[1<<15];
int main() {
	srand(time(0));
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%s",s[i]);
	int T=50,ans=0;
	long long S=0;
	for(int i=1;i<1<<k;i++)
		c[i]=c[i-(i&-i)]+1;
	while(T--) {
		int x=(rand()<<15|rand())%n+1,cnt=0;
		for(int i=0;i<m;i++)
			if(s[x][i]=='1')
				t[cnt++]=i;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) {
			int F=0;
			for(int j=0;j<cnt;j++)
				F|=(s[i][t[j]]-'0')<<j;
			f[F]++;
		}
		for(int i=1;i<1<<cnt;i++) {
			int S=((1<<cnt)-1)^i;
			for(int j=S;j;j=(j-1)&S)
				f[i]+=f[i^j];
		}
		for(int i=1;i<1<<cnt;i++) {
			if(f[i]*2>=n&&ans<c[i]) {
				S=0;
				ans=c[i];
				for(int j=0;j<cnt;j++)
					S|=1ll*(i>>j&1)<<t[j];
			}
		}
	}
	for(int i=0;i<m;i++)
		printf("%lld",S>>i&1);
	puts("");
	return 0;
}