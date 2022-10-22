#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define INF 0x3fffffffffffffff
int T,p[5];ll x[5],y[5],X[5],Y[5],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(ll x){if(x>=10)put(x/10);putchar(x%10+'0');}
ll calc(){For(i,1,4)X[i]=x[p[i]],Y[i]=y[p[i]];return abs(X[1]-X[3])+abs(X[2]-X[4])+abs(Y[1]-Y[2])+abs(Y[3]-Y[4])+2*max(0ll,max(min(X[2],X[4])-max(X[1],X[3]),min(Y[1],Y[2])-max(Y[3],Y[4]))-min(max(X[2],X[4])-min(X[1],X[3]),max(Y[1],Y[2])-min(Y[3],Y[4])));}
int main(){T=get();while(T--){For(i,1,4)x[i]=get(),y[i]=get(),p[i]=i;ans=INF;do{ans=min(ans,calc());}while(next_permutation(p+1,p+5));put(ans),putchar('\n');}return 0;}