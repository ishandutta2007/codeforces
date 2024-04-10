// by 

#include <map>
#include <cctype>
#include <cstdio>
#include <algorithm>

#define o c=getchar()
#define position(x) lower_bound(s+1,s+*s+1,x)-s

using namespace std;

typedef long long LL;

int n,Q,x,opt,l,r,m;
LL a[100006],s[200006];

struct bg{
    int pos;LL val,que;
}op[100006];

struct Sum{
    LL t[200005];
    void add(int x,int y){for(;x<=*s;x+=x&-x)t[x]+=y;}
    LL Qs(int x){LL y=0;for(;x;x-=x&-x)y+=t[x];return y;}
}sum;

struct Tot{
    int t[200005];
    void add(int x,int y){for(;x<=*s;x+=x&-x)t[x]+=y;}
    int Qs(int x){int y=0;for(;x;x-=x&-x)y+=t[x];return y;}
}tot;

template<typename T>inline void in(T &x){
    char c;while(!isdigit(o));for(x=0;isdigit(c);o)x=x*10-48+c;
}

int main(){
    in(n);in(Q);
    for(int i=1;i<=n;++i)in(a[i]),s[++*s]=a[i];
    for(int i=1;i<=Q;++i){
        in(opt);
        if(opt==1){
            in(op[i].pos);in(op[i].val);
            s[++*s]=op[i].val;
        }else   in(op[i].que);
    }
    sort(s+1,s+*s+1);
    for(int i=1;i<=n;++i){
        int index=position(a[i]);
        tot.add(index,1);
        sum.add(index,a[i]);
    }
    for(int i=1;i<=Q;++i){
        if(op[i].pos){
            int _=op[i].pos,index=position(a[_]);
            tot.add(index,-1);
            sum.add(index,-a[_]);
            index=position(a[_]=op[i].val);
            tot.add(index,1);
            sum.add(index,a[_]);
        }else{
            for(l=1,r=*s+1;l+1<r;){
                m=l+r>>1;
                if(1ll*tot.Qs(m)*s[m]-sum.Qs(m)<=op[i].que)l=m;else r=m;
            }
            LL _=1ll*tot.Qs(l);
            printf("%.5lf\n",1.*(op[i].que-_*s[l]+sum.Qs(l))/_+s[l]);
        }
    }
}