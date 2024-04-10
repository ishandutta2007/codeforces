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
int T,n,a[N],b[N],ans;
int main(){
	T=read();
	while(T--){
		n=read();
		ans=1;
		bool ok=false;
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		b[1]=1;
		for(int i=2;i<=n;++i){
			if(a[i]^a[i-1])b[i]=1+(b[i-1]&1);
			else b[i]=b[i-1],ok=true;
			ans=max(ans,b[i]);
		}
		if(a[1]^a[n]&&b[1]==b[n]){
			if(!ok)b[n]=3,ans=3;
			else{
				for(int i=2;i<=n;++i){
					if(a[i]==a[i-1]){
						b[i]=1+(b[i-1]&1);
						for(++i;i<=n;++i){
							b[i]=((a[i]^a[i-1])?1+(b[i-1]&1):b[i-1]);
						}
					}
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i){
			printf("%d ",b[i]);
		}
		printf("\n");
	}
	return 0;
}