#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 50050
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
int T,n,a[N],b[N];
char s[N];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		bool ok=false;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'){
				a[i]=b[i]=0;
			}
			else if(s[i]=='1'){
				if(ok)b[i]=1,a[i]=0;
				else ok=true,a[i]=1,b[i]=0;
			}
			else{
				if(ok)b[i]=2,a[i]=0;
				else a[i]=b[i]=1;
			}
		}
		for(int i=1;i<=n;++i){
			putchar(a[i]+'0');
		}
		putchar('\n');
		for(int i=1;i<=n;++i){
			putchar(b[i]+'0');
		}
		putchar('\n');
	}
	return 0;
}