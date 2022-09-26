#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200200
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
int T,n,a[N],cnt[N];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			cnt[i]=0;
		}
		int tot=0,mx=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			++cnt[a[i]];
			mx=max(mx,cnt[a[i]]);
			if(cnt[a[i]]==1)++tot;
		}
		printf("%d\n",min(tot,mx)-(tot==mx));
	}
	return 0;
}