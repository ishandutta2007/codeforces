#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,m,a[405][405],s[405][405],s2[405][405],S[405][405];char c[405];
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();
		for(int i=1;i<=n;++i){
			scanf("%s",c+1);
			for(int j=1;j<=m;++j){
				a[i][j]=(c[j]-'0');
				s[i][j]=s[i][j-1]+a[i][j];
				S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+a[i][j];
			}
		}
		for(int j=1;j<=m;++j){
			for(int i=1;i<=n;++i){
				s2[i][j]=s2[i-1][j]+a[i][j];
			}
		}
		int ans=n*m;
		for(int i=1;i<=n;++i){
			for(int j=i+4;j<=n;++j){
				int Min=1e9;
				for(int k=4;k<=m;++k){
					int t=k-3;
					Min=min(Min,-t*2+s[i][t]+s[j][t]+(j-i-1)-(s2[j-1][t]-s2[i][t])-S[j-1][t]+S[i][t]);
					ans=min(ans,(k-1)*2+(j-i-1)-(s2[j-1][k]-s2[i][k])-s[i][k-1]-s[j][k-1]+S[j-1][k-1]-S[i][k-1]+Min);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}