#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=3e5+7;
int n,ans,a[maxn],b[maxn],p[maxn],c[maxn];

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) {
        scanf("%d",&b[i]);
        p[b[i]]=i;
    }
    c[1]=p[a[1]];
    for (int i=2;i<=n;i++) c[i]=max(c[i-1],p[a[i]]);
    for (int i=2;i<=n;i++) if (p[a[i]]<c[i-1]) ++ans;
    printf("%d\n",ans);
    return 0;
}