#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
long f;
struct b
{
    long o,r,p;
}op[200005];
bool cmp(b a,b c)
{
    if(a.r!=c.r) return a.r>c.r;
    else return c.p>a.p;
}
int main()
{
    long n,m,i,j,a[200005],order[200005]={0},l=1,cur;
    multiset < long > v;
    multiset < long > :: iterator hi ,lo;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=0;i<m;++i)
    {
        cin>>op[i].o>>op[i].r;
        op[i].p=i+1;
    }
    sort(op,op+m,cmp);
    cur=0;
    for(i=1;i<=op[0].r;i++)
        v.insert(a[i]);
    for(i=0;i<m;++i)
    {
        if(op[i].p>cur)
        {
            cur=op[i].p;
            order[op[i].r]=op[i].o;
        }
    }
    for(i=n;i>0;--i)
    {
       if(order[i])
       {
          f=order[i];
          hi=v.begin();
          lo=v.end();
          lo--;
          if(f==1) {a[i]=*lo;v.erase(lo);}
          else {a[i]=*hi;v.erase(v.begin());}
          i--;
          while(order[i]==0 && i>0)
          {
              hi=v.begin();
              lo=v.end();
              lo--;
              if(f==1) {a[i]=*lo;v.erase(lo);}
              else {a[i]=*hi;v.erase(v.begin());}
              i--;
          }
          i++;
       }
    }
    for(i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}