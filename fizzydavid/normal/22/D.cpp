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
int n;
struct data
{
    int x,y;
    bool operator<(data tmp)const
    {
        if(x!=tmp.x)return x<tmp.x;
        return y<tmp.y;
    }
}a[1111];
vector<int>ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
    }
    sort(a+1,a+n+1);
    int i=1;
    while(i<=n)
    {
        int x=i,l=a[i].x,r=a[i].y;
        while(a[i].x<=a[x].y&&a[i].x<=r&&a[i].y>=l)
        {
            l=max(l,a[i].x);
            r=min(r,a[i].y);
            i++;
        }
        ans.pb(l);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}