#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int maxn=1e6+100;
const int M=998244353;
int ans,_,n,k,a[maxn],b[maxn],p[maxn],inv[maxn];
int main(){
    cin >> _;
    while (_--){
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) p[i]=0,inv[a[i]]=i;
        for (int i=1;i<=k;i++){
            int x;scanf("%d",&x);
            b[i]=inv[x];
            p[b[i]]=i;
        }
        ans=1;
        for (int i=1;i<=k;i++){
            int res=0;
            if (b[i]>1&&p[b[i]-1]<i) ++res;
            if (b[i]<n&&p[b[i]+1]<i) ++res;
            ans=ans*res%M;
        }
        printf("%d\n",ans);
    }
    return 0;
}