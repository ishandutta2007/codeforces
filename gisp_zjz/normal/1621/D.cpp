#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
typedef long long ll;
const int M=998244353;
const int maxn=1e6+10;
ll ans,a[1005][1005];
int n,_;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n*2;i++)
            for (int j=1;j<=n*2;j++)
                scanf("%lld",&a[i][j]);
        ans=1e9+1;
        for (int x=0;x<2;x++)
            for (int y=0;y<2;y++)
                for (int z=0;z<2;z++){
                    int p=1,q=1;
                    if (x) p+=n; else q+=n;
                    if (y) p+=n-1;
                    if (z) q+=n-1;
                    ans=min(ans,a[p][q]);
                }
        for (int i=n+1;i<=n*2;i++)
            for (int j=n+1;j<=n*2;j++)
                ans+=a[i][j];
        printf("%lld\n",ans);
    }
    return 0;
}