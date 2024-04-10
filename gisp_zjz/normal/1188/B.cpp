#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
ll x,n,k,p,ans,y;
map <ll,ll> f;

int main(){
    scanf("%I64d%I64d%I64d",&n,&p,&k);
    for (int i=0;i<n;i++){
        scanf("%I64d",&x);
        y=x*x%p*x%p*x%p;
        y=(k*x-y+p)%p;
        ans+=f[y];
        f[y]++;
    }
    printf("%I64d\n",ans);
    return 0;
}