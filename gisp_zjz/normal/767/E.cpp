#include<bits/stdc++.h>
#define maxn 102003
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
priority_queue <pi, vector <pi>, greater <pi> > q;
ll n,m,w[maxn],a[maxn],f[maxn],b[maxn],ans,o,c[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        c[i]=a[i]/100;
        a[i]%=100;
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        w[i]=b[i]*((100-a[i])%100);
    }
    for (int i=0;i<n;i++)
    {
        if (a[i]) q.push({w[i],i});
        o+=a[i];
        if (o>m) {
            m+=100;
            ans+=q.top().x;
            f[q.top().y]=1;
            q.pop();
        }
    }
    cout << ans << endl;
    for (int i=0;i<n;i++)
        if (f[i]) printf("%d 0\n",c[i]+1); else cout << c[i] << ' ' << a[i] << endl;
}