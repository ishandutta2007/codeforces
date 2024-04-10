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
int T,n,f[105][2],pre[105][2];char c[105],ans[105];
int main(){
	T=read()+1;
	while(--T){
		n=read();memset(f,0x3f,sizeof(f));
		memset(pre,0,sizeof(pre));
		scanf("%s",c+1);f[0][1]=f[0][0]=0;
		for(int i=1;i<=n;++i){
			if(c[i]=='?'||c[i]=='B'){
				f[i][0]=min(f[i-1][0]+1,f[i-1][1]);
				pre[i][0]=f[i-1][0]+1>f[i-1][1];
			}
			if(c[i]=='?'||c[i]=='R'){
				f[i][1]=min(f[i-1][1]+1,f[i-1][0]);
				pre[i][1]=f[i-1][1]+1<f[i-1][0];
			}
		}
		int now=f[n][0]>f[n][1];
		for(int i=n;i;--i){
			ans[i]=now?'R':'B';
			now=pre[i][now];
		}
		for(int i=1;i<=n;++i)putchar(ans[i]);puts("");
	}
	return 0;
}