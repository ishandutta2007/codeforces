#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,n,m,a[N],b[N],c[N],pos[N];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=m;++i){
			a[i]=c[i]=read(),b[i]=read();
			pos[i]=i;
		}
		sort(c+1,c+m+1,greater<int>());
		sort(pos+1,pos+m+1,[](int i,int j){return b[i]>b[j];});
		int now=0;
		ll ans=0,tot=0;
		for(int i=1;i<=m;++i){
			int u=pos[i];
			if(now)tot-=c[now--];
			while(now<n-(a[u]<=b[u])&&now<m&&c[now+1]>b[u])++now,tot+=c[now];
			if(a[u]<=b[u]){
				ans=max(ans,a[u]+tot+1LL*(n-now-1)*b[u]);
			}
			else{ 
				ans=max(ans,tot+1LL*(n-now)*b[u]);
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}