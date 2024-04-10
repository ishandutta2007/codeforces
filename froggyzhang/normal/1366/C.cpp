#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,a[233][233],n,m,cnt[2][233];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=read();
			}
		}
		memset(cnt,0,sizeof(cnt));
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(i+j-1==n-i+1+m-j+1-1)continue;
				cnt[a[i][j]][min(i+j-1,(n-i+1)+(m-j+1)-1)]++;
			}
		}
		for(int i=1;i<=n+m;++i){
			ans+=min(cnt[0][i],cnt[1][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}