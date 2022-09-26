#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 300030
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
ll tot;
int n,a[N],x,id[N],cnt0[N],cnt1[N],to[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		id[i]=1;
	}
	int now=1;
	for(int j=30;j>=0;--j){
		ll c0=0,c1=0;
		memset(cnt0,0,sizeof(cnt0));
		memset(cnt1,0,sizeof(cnt1));
		memset(to,255,sizeof(to));
		for(int i=1;i<=n;++i){
			if(a[i]>>j&1){
				c1+=cnt1[id[i]];
				++cnt0[id[i]]; 
			}
			else{
				c0+=cnt0[id[i]];
				++cnt1[id[i]]; 
			}
		}
		for(int i=1;i<=n;++i){
			if(!cnt0[id[i]]||!cnt1[id[i]])continue;
			if(!~to[id[i]])to[id[i]]=++now;
			if(a[i]>>j&1)id[i]=to[id[i]];
		}
		if(c1<c0){
			x^=1<<j;
		}
		tot+=min(c0,c1);
	}
	printf("%lld %d\n",tot,x);
	return 0;
}