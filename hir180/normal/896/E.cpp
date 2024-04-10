#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,unsafe-math-optimizations")
#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
inline int read_char() {
    static char buf[1 << 16], *ptr = buf, *end_ptr = buf;
    if (ptr == end_ptr) {
        int len = fread(buf, 1, sizeof(buf), stdin);
        if (len <= 0) return EOF;
        ptr = buf;
        end_ptr = buf + len;
    }
    return *ptr++;
}
inline int readint(){
    int t=0;
    char c;
    bool negative=false;
    c=read_char();
    while(c<'0'&&c>'9'){
        if(c=='-')
            negative=true;
        c=read_char();
    }
    while(c>='0'&&c<='9'){
        t=(t<<3)+(t<<1)+c-'0';
        c=read_char();
    }
    if(negative)
        t=~(t-1); //negative
    return t;
}

inline void printint(int a){
    if(a==0){putchar('0');return;}
    char buf[10],x=0;
    while(a){
        buf[x++]=a%10;
        a/=10;
    }
    while(x){
        putchar(buf[--x]+48);
    }
}
float __attribute__((aligned(64))) a[100005],x;
int n,m,t,l,r,ans;
int main(){
    n=readint(); m=readint(); 
	for(int i=1;i<=n;i++) a[i]=readint(); //cout<<a[i]<<endl;
	for(int i=0;i<m;i++){
		t=readint(); l=readint(); r=readint(); x=readint();
		if(t == 1){
			for(int j=l;j<=r;j++) a[j] -= a[j]>x?x:0;
		}
		else{
			ans=0;
			for(int j=l;j<=r;j++) ans+=(a[j]==x);
			printint(ans); putchar('\n');
		}
	}
}