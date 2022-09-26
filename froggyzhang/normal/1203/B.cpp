#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 2333
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
int T,n,a[N],b[N],bn;
int main(){
	T=read();
	while(T--){
		n=(read()<<2);
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		bool ok=true;
		bn=0;
		for(int i=1;i<=n;i+=2){
			b[++bn]=a[i];
			if(a[i]^a[i+1]){
				ok=false;
				break;
			}
		}
		if(!ok){
			printf("NO\n");
			continue;
		}
		int tmp=b[1]*b[bn];
		for(int i=2;i<=bn/2;++i){
			if(b[i]*b[bn-i+1]!=tmp){
				ok=false;
				break;
			}
		}
		if(ok){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}