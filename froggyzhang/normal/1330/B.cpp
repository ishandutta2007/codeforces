#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int T,n;
int a[N],ans[N],an;
int lcnt[N],rcnt[N];
int main(){
	T=read();
	while(T--){
		n=read();
		an=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		memset(lcnt,0,sizeof(lcnt));
		memset(rcnt,0,sizeof(rcnt));
		int lpos=0,rpos=0;
		for(int i=1;i<=n;++i){
			++rcnt[a[i]];
		}
		while(rcnt[rpos+1]==1)++rpos;
		for(int i=1;i<n;++i){
			++lcnt[a[i]],--rcnt[a[i]];
			if(lpos>=a[i]&&lcnt[a[i]]==2)lpos=a[i]-1;
			if(rpos>=a[i]&&rcnt[a[i]]==0)rpos=a[i]-1;
			while(lcnt[lpos+1]==1)++lpos;
			while(rcnt[rpos+1]==1)++rpos;
			if(lpos==i&&rpos==n-i)ans[++an]=i;
		}
		printf("%d\n",an);
		for(int i=1;i<=an;++i){
			printf("%d %d\n",ans[i],n-ans[i]);
		}
	}
	return 0;
}