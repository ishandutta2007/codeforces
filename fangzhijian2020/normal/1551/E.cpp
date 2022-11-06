#include<iostream> 
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,m,a[2005],f[2005][2005];
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();
		memset(f,-0x3f,sizeof(f));
		for(int i=1;i<=n;++i)a[i]=read();
		f[0][0]=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=i;++j){
				if(j)f[i][j]=max(f[i-1][j],f[i-1][j-1]+(a[i]==j));
				else f[i][j]=f[i-1][j];
			}
		}
		int opt=1;
		for(int i=n;i;--i){
			if(f[n][i]>=m){
				cout<<n-i<<"\n";opt=0;break;
			}
		}
		if(opt){
			puts("-1");
		}
	}
	return 0;
}