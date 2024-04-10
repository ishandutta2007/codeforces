#include<bits/stdc++.h>
using namespace std;
const int N=4e5+1;
const long long MOD=1e9+7;
long long a[N],ni[N];
long long all,v;
int n,k;
long long calc(long long x,long long y){
    long long z=1;
    while (y){
        if (y&1)(z*=x)%=MOD;
        (x*=x)%=MOD,y/=2;
    }
    return z;
}
long long C(int x,int y){
    if (y>x)return 0;
    return a[x]*ni[y]%MOD*ni[x-y]%MOD;
}
long long S(int n,int k){
    long long s=0,sig=1;
    if (k&1)sig=MOD-1;
    for (int i=0;i<=k;i++){
        (s+=C(k,i)*sig%MOD*calc(i,n)%MOD)%=MOD;
        sig=MOD-sig;
    }
    return s*ni[k]%MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    a[0]=1;
    for (int i=1;i<N;i++)a[i]=a[i-1]*i%MOD;
    ni[N-1]=calc(a[N-1],MOD-2);
    for (int i=N-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%MOD;
   /* for (int i=1;i<=n;i++)
        (v+=C(n-1,i-1)*S(n-i,k-1)%MOD*i%MOD)%=MOD;*/
    v=(S(n,k)+(n-1)*S(n-1,k))%MOD;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        (all+=x)%=MOD;
    }
    cout<<v*all%MOD;
    return 0;
}