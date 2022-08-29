#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
    ll x=0;char ch=getchar();
    while (ch<'0'){ch=getchar();};
    while (ch>='0'){x=(x<<1)+(x<<3)+ch-48;ch=getchar();};
    return x; 
}
ll n,m,g[21][100201],Q[1400021],F[1400022],S[1400201];
inline void FWTxor(ll *a,int id,int lim){
    for (int len=1;len<lim;len<<=1){
        for (int i=0;i<lim;i+=len<<1){
            ll *a1=a+i,*a2=a1+len;
            for (int j=0;j<len;j++){
                ll x=a1[j],y=a2[j];
                a1[j]=(x+y)/(id==1?1:2);
                a2[j]=(x-y)/(id==1?1:2);
            }
        }
    }
}
int main(){
    n=read(),m=read();
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;j++){
            g[i][j]=getchar()-'0';
        }getchar();
    }
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;j++){
            S[i]|=(1<<j-1)*g[j][i];
        }
    }
    for (int i=0;i<=(1<<n);++i){
        Q[i]=__builtin_popcount(i);
    }
    for (int i=0;i<=(1<<n);++i){
        Q[i]=min(Q[i],n-Q[i]);
    }
    for (int i=1;i<=m;++i)++F[S[i]];
    FWTxor(F,1,1<<n);FWTxor(Q,1,1<<n);
    for (int i=0;i<(1<<n);++i) F[i]*=Q[i];
    FWTxor(F,-1,1<<n);
    ll x=1e18;
    for (int i=0;i<(1<<n);++i) x=min(F[i],x);
    cout<<x<<endl;
}