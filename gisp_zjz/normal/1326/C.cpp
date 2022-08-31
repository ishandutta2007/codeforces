#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+3;
const int M=998244353;
int n,k,a[maxn],b[maxn],ans;
ll tot;

int main(){
    scanf("%d%d",&n,&k);
    for (int i=n-k+1;i<=n;i++) tot=tot+i;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int last=-1; ans=1;
    for (int i=1;i<=n;i++) if (a[i]>n-k){
        if (last!=-1) ans=1ll*ans*(i-last)%M;
        last=i;
    }
    printf("%lld %d\n",tot,ans);
    return 0;
}