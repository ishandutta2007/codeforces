#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const char str[4][5]={"0011","0101","1110","1111"};
const int N=3010,mod=1e9+7,M=9000011;
int a[N],f[N][N];
int check(int x,int y) {
	for(int i=0;i<4;i++) {
		int FL=1;
		for(int j=x;j<=y;j++)
			if(str[i][j-x]-'0'!=a[j])FL=0;
		if(FL)return 0;
	}
	return 1;
}
int nxt[M],hea[M],tot;
ull to[M];
int find(ull x) {
	int a=x%M;
	for(int i=hea[a];i;i=nxt[i])
		if(to[i]==x)return 1;
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=x;
	return 0;
}
int main() {
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",a+i);
	for(int i=1;i<=m;i++) {
		f[i][i-1]=1;
		for(int j=i;j<=m;j++)
			for(int k=j;k>=i&&k>=j-3;k--) {
				if(k>j-3)f[i][j]=(f[i][j]+f[i][k-1])%mod;
				else if(check(k,j))f[i][j]=(f[i][j]+f[i][k-1])%mod;
			}
	}
	int ans=0;
	for(int i=1;i<=m;i++) {
		ull H=0;
		for(int j=i;j>=1;j--) {
			H=3*H+a[j]+1;
			if(!find(H))
				ans=(ans+f[j][i])%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}