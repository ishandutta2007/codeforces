#include <bits/stdc++.h>
#define long long long
#define pb push_back
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long h,q,i,l,r,x,j=0,ans,cur=0,ans2=0;
vll v,vv;
int main()
{
    io
    cin>>h>>q;
    long pmn=(1LL<<(h-1)),pmx=(1LL<<h)-1;
    for(i=0;i<q;++i)
    {
        cin>>x>>l>>r>>ans;
        while(x<h)
        {
            l=2*l;
            r=2*r+1;
            x++;
        }
        if(ans)
        {
            pmn=max(pmn,l);
            pmx=min(pmx,r);
        }
        else
        {
            v.pb({l,-1});
            v.pb({r+1,1});
        }
    }
    v.pb({pmn,1});
    v.pb({pmx+1,-1});
    sort(v.begin(),v.end());
    ml mp;
    ml ::iterator it,jt;
    for(i=0;i<v.size();++i)
    {
        cur+=v[i].y;
        mp[v[i].x]=cur;
    }
    for(it=mp.begin();it!=mp.end();it++)
    {
        if((it->y)>0)
        {
            jt=it;
            jt++;
            vv.pb({it->x,jt->x-1});
        }
    }
    for(i=0;i<vv.size();++i)
    ans2+=max(0LL,vv[i].y-vv[i].x+1);
    if(ans2>1) cout<<"Data not sufficient!";
    else if(ans2) cout<<vv[0].x;
    else cout<<"Game cheated!";
    return 0;
}