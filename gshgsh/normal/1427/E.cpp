#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define lowbit(x) (x&-x)
#define MAXN 100001
int cnt;ll X[MAXN],Y[MAXN],OPT[MAXN];ll opt(ll x,ll y,bool op){X[++cnt]=x,Y[cnt]=y,OPT[cnt]=op;return op?x^y:x+y;}
int nxt(int x){ll y=x,tmp=x>>1;while(tmp)y=opt(y,y,0),tmp>>=1;ll z=opt(x,y,1);ll a=opt(y,z,0);ll b=opt(opt(opt(y,y,0),a,1),x,1);while(y!=lowbit(y)){if(y&b)y=opt(y,b,1);b=opt(b,b,0);}return opt(x,y,1);}
int main(){int x;cin>>x;while(x!=1)x=nxt(x);cout<<cnt<<endl;For(i,1,cnt)cout<<X[i]<<' '<<(OPT[i]?'^':'+')<<' '<<Y[i]<<endl;return 0;}