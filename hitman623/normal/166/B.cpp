#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vll p;
long t,n,i;
vll v;
long o(pll a , pll b , pll c)
{
    long m=(c.y-b.y)*(b.x-a.x)-(b.y-a.y)*(c.x-b.x);
    if(m==0) return 0;
    if(m>0) return 2;
    return 1;
}
bool cmp(pll a , pll b)
{
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
double dist(pll a , pll b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp2(pll a , pll b)
{
    if(o(v[0],a,b)==2) return 1;
    if(o(v[0],a,b)==0) return dist(v[0],a)<dist(v[0],b);
    return 0;
}
pll nextToTop(stack< pll > &S)
{
    pll p = S.top();
    S.pop();
    pll res = S.top();
    S.push(p);
    return res;
}
void solve()
{
    long i;
    sort(v.begin(),v.end(),cmp);
    p.pb(v[0]);
    sort(v.begin()+1,v.end(),cmp2);
    i=n-2;
    while(o(v[0],v[n-1],v[i])==0)
    i--;
    reverse(v.begin()+i+1,v.end());
    stack < pll > S;
    S.push(v[0]);
    S.push(v[1]);
    if(v.size()<3) goto u;
    S.push(v[2]);
    for (i = 3; i < v.size(); i++)
    {
        if(!S.empty())
        while (o(nextToTop(S), S.top(), v[i])==1)
        {
            if(S.empty()) break;
            S.pop();
        }
        S.push(v[i]);
    }
    u:
    p.clear();
    while(!S.empty())
    {
        p.pb(S.top());
        S.pop();
    }
    reverse(p.begin(),p.end());
}
int main()
{
    io
    long a,b,i;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a>>b;
        v.pb({a,b});
    }
    solve();
    vll A=p;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a>>b;
        v.pb({a,b});
    }
    n=v.size();
    p.clear();
    solve();
    if(A==p) cout<<"YES";
    else cout<<"NO";
    return 0;
}