#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
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
int T,n;
char s[N],t[N];
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		int pos=1,a=0,b=0;
		while(pos<=n&&s[pos]=='0'){
			++pos;
		}
		a=pos-1;
		pos=n;
		while(pos>=1&&s[pos]=='1'){
			--pos;
		}
		b=n-pos;
		for(int i=1;i<=a;++i){
			putchar('0');
		}
		if(a+b<n)putchar('0');
		for(int i=1;i<=b;++i){
			putchar('1');
		}
		putchar('\n');
	}
	return 0;
}