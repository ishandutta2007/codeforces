//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,l,x,y,a[100111];
set<int>s;
int solve(int d)
{
    for(int i=1;i<=n;i++)
    {
        if(s.count(a[i]+d)>0)return 0;
    }
    return d;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>l>>x>>y;int tmp;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        s.insert(tmp);
        a[i]=tmp;
    }
    int ansl=solve(x),ansr=solve(y);
    if(ansl>0&&ansr>0)
    {
        int ok=0;
        for(int i=1;i<=n;i++)
        {
            if(s.count(a[i]+y-x)>0&&(a[i]-x>0||a[i]+y<l))
            {
                if(a[i]-x>0)ok=a[i]-x;else ok=a[i]+y;
                break;
            }
            if(s.count(a[i]+y+x)>0&&a[i]+x<l)
            {
                ok=a[i]+x;
                break;
            }
        }
        if(ok>0&&ok<l)
        {
            cout<<1<<endl<<ok;
        }
        else
        {
            cout<<2<<endl<<ansl<<" "<<ansr;
        }
    }
    else if(ansl>0)
    {
        cout<<1<<endl<<ansl;
    }
    else if(ansr>0)
    {
        cout<<1<<endl<<ansr;
    }
    else
    {
        cout<<0;
    }
    return 0;
}