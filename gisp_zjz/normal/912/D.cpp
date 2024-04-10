#include<bits/stdc++.h>
#define maxn 203040
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
priority_queue <pii> p;
pii tmp;
pi tt;

double ans;
ll n,m,q,r,k,c,s,t,a[maxn],w,r1,r2;

int main()
{
    scanf("%d%d%d%d",&n,&m,&r,&k);
    s=(n+1)/2; t=(m+1)/2;
    r1=min(r,n-r+1); r2=min(r,m-r+1);
    for (ll i=1;i<=s;i++)
    {
        a[i]=t;
        tmp.x=min(i,r1)*min(t,r2);
        tmp.y={i,t};
        p.push(tmp);
    }
    c=0;
    while (k>0)
    {
        tmp=p.top();p.pop();
        w=4;
        tt=tmp.y;
        if (tt.x*2>n) w/=2;
        if (tt.y*2>m) w/=2;
        w=min(w,k);
        c+=w*tmp.x;
        k-=w;
        if (tt.y>0){
            tt.y--;
            tmp.x=min(tt.x,r1)*min(tt.y,r2);
            tmp.y=tt;
            p.push(tmp);
        }
    }
    ans=(double)c;
    ans=ans/((n-r+1)*(m-r+1));
    printf("%.10f\n",ans);
    return 0;
}