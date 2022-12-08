#include<bits/stdc++.h>
using namespace std;
const int N=1510,mod=1e9+9;
int a[N],tr[N][4],fail[N],en[N],q[N],f[N][N][11],tot;
char s[N];
int get(char c) {
	if(c=='A')return 0;
	if(c=='T')return 1;
	if(c=='C')return 2;
	return 3;
}
int main() {
	int n,m,Mx=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%s",s+1);
		int len=strlen(s+1),p=0;
		Mx=max(Mx,len);
		for(int j=1;j<=len;j++) {
			int c=get(s[j]);
			if(!tr[p][c])tr[p][c]=++tot;
			p=tr[p][c];
		}
		en[p]=len;
	}
	int h=1,e=0;
	for(int i=0;i<4;i++)
		if(tr[0][i])q[++e]=tr[0][i];
	while(h<=e) {
		int x=q[h++];
		en[x]=max(en[x],en[fail[x]]);
		for(int i=0;i<4;i++)
			if(!tr[x][i])tr[x][i]=tr[fail[x]][i];
			else fail[q[++e]=tr[x][i]]=tr[fail[x]][i];
	}
	f[0][0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<=tot;j++)
			for(int k=0;k<=Mx;k++)
				for(int l=0;l<4;l++)
					(f[i+1][tr[j][l]][(k<en[tr[j][l]])?0:min(Mx,k+1)]+=f[i][j][k])%=mod;
	int ans=0;
	for(int i=0;i<=tot;i++)
		(ans+=f[n][i][0])%=mod;
	printf("%d\n",ans);
	return 0;
}