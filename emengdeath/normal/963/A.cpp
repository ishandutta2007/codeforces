#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+9;
long long a,b,n,ans,k,v,u;
long long calc(long long x,long long y){
    long long s=1;
    while (y){
        if (y&1)(s*=x)%=MOD;
        (x*=x)%=MOD,y/=2;
    }
    return s;
}
long long ni(long long x){
    return calc(x,MOD-2);
}
long long dfs(int l,int r){
    long long s=0;
    if (l==r)
        return calc(v,l)*u%MOD;
    int len=r-l+1;
    s=dfs(l,l+len/2-1);
    if (len&1){
        return (s*(1+calc(v,len/2))%MOD+dfs(r,r))%MOD;    
    }else{
        return s*(1+calc(v,len/2))%MOD;
    }       
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>a>>b>>k;
    long long nia=ni(a);
    v=1;
    for (int i=0;i<k;i++){
        char c;
        cin>>c;
        v=v*nia%MOD*b%MOD;
        if (c=='+')
            (u+=calc(a,n-i)*calc(b,i)%MOD)%=MOD;
        else
            (u+=MOD-calc(a,n-i)*calc(b,i)%MOD)%=MOD;
    }
    n=(n+1)/k;
    cout<<dfs(0,n-1)<<endl;
    return 0;
}