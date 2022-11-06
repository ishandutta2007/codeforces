#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,n,m,k,p[105][105],opt[105][105],f[15][1024],num[105],val[105],ans=1e9;
int main(){
//	system("fc table.out table2.out");
//	freopen("table.in","r",stdin);
//	freopen("table.out","w",stdout);
//	T=read()+1;
//	while(--T){
		n=read();m=read();k=read();ans=1e9;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)p[i][j]=read();
		}
		if(n<m){
			swap(n,m);
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j)opt[i][j]=p[j][i];
			}
		}
		else{
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j)opt[i][j]=p[i][j];
			}
		}
		if(n<=10){
			memset(f,0x3f,sizeof(f));
			for(int i=1;i<=n;++i){
				val[i]=0;
				for(int j=1;j<=m;++j){
					val[i]=(val[i]<<1)+opt[i][j];
				}
			}
			for(int i=0;i<(1<<m);++i){
				num[i]=num[i>>1]+(i&1);
				f[0][i]=0;
			}
			int N=(1<<m)-1;
			for(int i=1;i<=n;++i){
				for(int j=0;j<(1<<m);++j){
					f[i][j]=min(f[i][j],min(f[i-1][j],f[i-1][N^j])+num[val[i]^j]);
					if(i==n)ans=min(ans,f[i][j]);
				}
			}
		}
		else{
			for(int i=1;i<=n;++i){
				int sum=0;
				for(int j=1;j<=n;++j){
					int tmp1=0,tmp2=0;
					for(int k=1;k<=m;++k){
						if(opt[i][k]==opt[j][k])++tmp1;
						else ++tmp2;
					}
					sum+=min(tmp1,tmp2);
				}
				ans=min(ans,sum);
			}
		}
		if(ans<=k)printf("%d\n",ans);
		else puts("-1");
//	}
	return 0;
}