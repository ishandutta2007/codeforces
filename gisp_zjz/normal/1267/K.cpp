#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,tot,a[100],cnt[100];
ll n,C[100][100];
ll work(ll x){
    for (int i=x+1;i<100;i++) if (cnt[i]) return 0;
    ll res=1; int pos=0;
    for (int i=x;i;i--){
        pos++;
        if (pos<cnt[i]) return 0;
        res=res*C[pos][cnt[i]];
        pos-=cnt[i];
    }
    return res;
}
int main(){
    scanf("%d",&T);
    for (int i=0;i<100;i++){
        C[i][0]=C[i][i]=1;
        for (int j=1;j<i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    while (T--){
        scanf("%lld",&n);
        tot=0;
        while (n){
            ++tot;
            a[tot]=n%(tot+1);
            n/=tot+1;
        }
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=tot;i++) cnt[a[i]]++;
        ll ans=work(tot);
        if (cnt[0]) ans-=work(tot-1);
        printf("%lld\n",ans-1);
    }
    return 0;
}