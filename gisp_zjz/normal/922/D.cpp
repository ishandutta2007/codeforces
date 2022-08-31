#include<bits/stdc++.h>
#define maxn 500050
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

pi a[maxn];

bool cmp(pi u,pi v)
{
    if (u.y==0&&v.y==0) return u.x<v.x;
    if (u.y==0) return true;
    if (v.y==0) return false;
    return u.x*v.y>v.x*u.y;
}

ll ans,n,cnt,r;
char s[maxn];

int main()
{
    scanf("%d",&n); ans=0;
    for (int i=0;i<n;i++)
    {
        scanf("%s",s);
        r=strlen(s);
        cnt=0;
        for (int j=0;j<r;j++)
            if (s[j]=='s') cnt++; else ans+=cnt;
        a[i].x=cnt; a[i].y=r-cnt;
    }
    sort(a,a+n,cmp); cnt=0;
    for (int i=0;i<n;i++) ans+=cnt*a[i].y,cnt+=a[i].x;
    printf("%I64d\n",ans);
}