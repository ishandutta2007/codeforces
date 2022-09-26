#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 400040
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
int n,a[N],cnt[20000007],ans,las;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int k=0;k<=24;++k){
		int tmp=0;
		for(int i=1;i<=n;i++){
			if((a[i]>>k)&1)tmp^=1;
		}
		if(n&1)tmp=0;
		ans+=(tmp^las)<<k;
		las=0;
		int pp=0;
		for(int j=0;j<=k;j++){
			for(int i=1;i<=n;i++){
				int c=(a[i]>>(k-j+1)&pp);
				if(a[i]>>(k-j)&1)++cnt[c];
			}
			for(int i=1;i<=n;i++){
				int c=(a[i]>>(k-j+1)&pp);
				if(a[i]>>(k-j)&1)--cnt[c],c^=pp,las^=(cnt[c]&1);
			}
			pp=(pp<<1|1);
		}
	}
	cout<<ans<<endl;
	return 0;
}