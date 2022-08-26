#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=7005;
ll n,a[maxn],b[maxn],c[maxn],m;
map <ll,ll> f;
map <ll,ll> g;
ll v,ans,cnt,ret;

int main(){
    scanf("%lld",&n);
    for (int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        f[a[i]]++;
    }
    for (int i=0;i<n;i++){
        scanf("%lld",&b[i]);
    }
    ret=0;
    for (int i=0;i<n;i++) if (f[a[i]]>=2){
        ret+=b[i];
        c[++m]=a[i];
    }
    for (int i=0;i<n;i++) if (f[a[i]]<2){
        bool flag=0;
        for (int j=1;j<=m;j++) flag|=((a[i]&c[j])==a[i]);
        if (flag) ret+=b[i];
    }
    printf("%lld\n",ret);
    return 0;
}