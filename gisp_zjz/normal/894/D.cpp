#include<bits/stdc++.h>
#define maxn 1020300

using namespace std;
typedef long long ll;
struct node{
    ll o,h,p,num;
};
ll m,n,q,l[maxn],r[maxn],v[maxn];
ll b[maxn],c[maxn];
ll h[maxn],ans[maxn];
node a[maxn*4];

bool cmp(node u,node v){
    if (u.h!=v.h) return u.h<v.h;
    else return u.o<v.o;
}

int main()
{
    scanf("%lld",&n);scanf("%lld",&m); q=m; m=0;
    for (int i=2;i<=n;i++) scanf("%lld",&v[i]);
    for (int i=2;i<=n;i++) h[i]=h[i/2]+v[i];

    for (int i=0;i<q;i++)
    {
        ll u,w; scanf("%lld%lld",&u,&w);
        a[m].o=1;
        a[m].h=h[u]+w; a[m].p=u; a[m].num=i; m++;
        while (u>1&&w>v[u]){
            w-=v[u]; ans[i]+=w;
            a[m].p=u^1;
            u/=2;
            a[m].h=w+h[u];
            a[m].num=i;
            a[m].o=1;
            m++;
        }
    }
    for (int i=1;i<=n;i++) {
        a[m].h=h[i]; a[m].o=2; a[m].p=i;
        m++;
    }
    sort(a,a+m,cmp);
    for (int i=0;i<m;i++){
        if (a[i].o==2){
            int t=a[i].p;
            while (t){
                b[t]+=h[a[i].p];
                c[t]++;
                t>>=1;
            }
        }
        else {
            ans[a[i].num]+=c[a[i].p]*a[i].h-b[a[i].p];
        }
    }
    for (int i=0;i<q;i++) cout << ans[i] << endl;
    return 0;
}