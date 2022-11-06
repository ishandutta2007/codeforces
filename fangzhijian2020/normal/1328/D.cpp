#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,t[200005],f[200005][2],pre[200005][2],ans[200005];
int main(){
	T=read()+1;
	while(--T){
		n=read();int opt=1;
		for(int i=1;i<=n;++i){
			t[i]=read();if(i>1&&t[i]!=t[i-1])opt=0;
		}
		f[1][0]=1;f[1][1]=0;
		for(int i=2;i<=n;++i){
			if(t[i]==t[i-1]){
				f[i][0]=f[i][1]=(f[i-1][0]|f[i-1][1]);
				pre[i][0]=pre[i][1]=f[i-1][0]?0:1;
			}
			else{
				f[i][0]=f[i-1][1];pre[i][0]=1;
				f[i][1]=f[i-1][0];pre[i][1]=0;
			}
		}
		if(opt){
			puts("1");
			for(int i=1;i<=n;++i)cout<<1<<" ";puts("");
		}
		else if(f[n][1]||(t[1]==t[n]&&f[n][0])){
			int now=f[n][1]?1:0;
			for(int i=n;i;--i){
				ans[i]=now;now=pre[i][now];
			}
			puts("2");
			for(int i=1;i<=n;++i)cout<<ans[i]+1<<" ";puts("");
		}
		else{
			puts("3");
			cout<<3<<" ";
			for(int i=2;i<=n;++i)cout<<(i&1)+1<<" ";puts("");
		}
	}
	return 0;
}