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
int n,T,t,a[N];
void Solve(){
	n=read(),t=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	int qwq=0;
	for(int i=1;i<=n;++i){
		if(!(t&1)&&a[i]==t/2){
			putchar(qwq+'0');
			qwq^=1;
		}
		else if(a[i]<=t/2){
			putchar('0');
		}
		else{
			putchar('1');
		}
		putchar(' ');
	}
	putchar('\n');
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}