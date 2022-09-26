#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 1010
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
int T,n,pre[N],suf[N],pre_pos[N],suf_pos[N]; 
int a[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		bool ok=false;
		pre[0]=suf[n+1]=inf;
		for(int i=1;i<=n;++i){
			pre[i]=pre[i-1],pre_pos[i]=pre_pos[i-1];
			if(a[i]<pre[i])pre[i]=a[i],pre_pos[i]=i;
		}
		for(int i=n;i>=1;--i){
			suf[i]=suf[i+1],suf_pos[i]=suf_pos[i+1];
			if(a[i]<suf[i])suf[i]=a[i],suf_pos[i]=i;
		}
		for(int i=1;i<=n;++i){
			if(a[i]>pre[i-1]&&a[i]>suf[i+1]){
				printf("YES\n%d %d %d\n",pre_pos[i],i,suf_pos[i]);
				ok=true;
				break;
			}
		}
		if(!ok)printf("NO\n");
	
	}
	return 0;
}