#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=5e5+3;
typedef long long ll;
typedef pair<int,int> pi;
int n,m,d,cnt,a[maxn],ans;
map <int,int> f;
set <int> s;
int main(){
    scanf("%d%d",&n,&m);
    m=m*8/n; m=min(m,30); d=1<<m;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=0;i<n;i++) if (s.find(a[i])==s.end()) s.insert(a[i]);
    for (auto x:s) f[x]=++cnt;
    for (int i=0;i<n;i++) a[i]=f[a[i]];
    for (int i=0;i<n;i++) ans=max(ans,lower_bound(a,a+n,a[i]+d)-a-i);
    printf("%d\n",n-ans);
    return 0;
}