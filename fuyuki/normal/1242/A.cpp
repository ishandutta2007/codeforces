#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
    rnt _s=0;re char _ch=gc;
    while(!isnum(_ch))_ch=gc;
    while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
    return _s;
}
ll n,x,p;
V input(){cin>>n,x=sqrt(n);}
int tot,flag;
ll a[1000];
V init(){
    p=n,flag=1;
    FOR(i,2,x)if(p%i==0){
        a[++tot]=i,flag=0;
        while(p%i==0)p/=i;
        x=sqrt(p);
    }
    if(p>1)a[++tot]=p;
}
V work(){
    if(flag)return void(cout<<n);
    if(tot==1)return void(cout<<a[1]);
    cout<<1;
}
int main(){
    input();
    init();
    work();
    return 0;
}