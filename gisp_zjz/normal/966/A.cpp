#include<bits/stdc++.h>
#define maxn 510300
#define F first
#define S second

using namespace std;
typedef long long ll;
const ll inf=1e14;
typedef pair<ll,ll> pi;
ll a[maxn],b[maxn];
ll n,m,p,q,v,x,y,z,w,t,l,r,mid,ans,pos1,pos2;

ll f1(ll o)
{
    l=-1; r=p;
    while (r-l>1){
        mid=(l+r)/2;
        if (a[mid]>o) r=mid; else l=mid;
    }
    return l;
}

ll f2(ll o)
{
    l=-1; r=q;
    while (r-l>1){
        mid=(l+r)/2;
        if (b[mid]>o) r=mid; else l=mid;
    }
    return l;
}

ll f(ll x)
{
    return (x+v-1)/v;
}

int main()
{
    scanf("%d%d%d%d%d",&n,&m,&p,&q,&v);
    for (int i=0;i<p;i++) scanf("%d",&a[i]); sort(a,a+p);
    for (int i=0;i<q;i++) scanf("%d",&b[i]); sort(b,b+q);
    cin >> t;
    while (t--){
        scanf("%d%d%d%d",&x,&y,&z,&w);
        ans=inf;
        if (x==z) {
            cout << abs(w-y) << endl;
            continue;
        }
        if (p){
            pos1=f1(y);
            pos2=f1(w);
            if (pos2-pos1) ans=min(ans,abs(y-w)+abs(x-z));
            else {
                if (pos1>=0) ans=min(ans,abs(x-z)+abs(y-a[pos1])+abs(w-a[pos1]));
                if (pos2+1<p) ans=min(ans,abs(x-z)+abs(y-a[pos2+1])+abs(w-a[pos2+1]));
            }
        }
        if (q){
            pos1=f2(y);
            pos2=f2(w);
            if (pos2-pos1) ans=min(ans,abs(y-w)+f(abs(x-z)));
            else {
                if (pos1>=0) ans=min(ans,f(abs(x-z))+abs(y-b[pos1])+abs(w-b[pos1]));
                if (pos2+1<q) ans=min(ans,f(abs(x-z))+abs(y-b[pos2+1])+abs(w-b[pos2+1]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}