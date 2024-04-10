#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=505050;
typedef pair<ll,ll> pi;
struct mv{
    ll x,y,d;
};
pi a[maxn],b[maxn];
vector <mv> ans;
int n,p,q;
ll h,v[maxn];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%I64d",&a[i].F);
        a[i].S=i;
    }
    for (int i=1;i<=n;i++){
        scanf("%I64d",&b[i].F);
        b[i].S=i;
    }
    sort(a+1,a+1+n); sort(b+1,b+1+n);
    for (int i=1;i<=n;i++){
        v[i]=b[i].F-a[i].F;
        h+=v[i];
        if (h<0) {puts("NO");return 0;}
    }
    if (h!=0) {puts("NO");return 0;}
    p=1; q=1;
    while (true){
        while (p<=n&&v[p]<=0) ++p;
        while (q<=n&&v[q]>=0) ++q;
        if (p>n||q>n) break;
        ll dis=min(v[p],-v[q]);
        ans.push_back((mv){a[p].S,a[q].S,dis});
        v[p]-=dis; v[q]+=dis;
    }
    puts("YES");
    printf("%d\n",ans.size());
    for (auto x:ans) printf("%I64d %I64d %I64d\n",x.x,x.y,x.d);
}