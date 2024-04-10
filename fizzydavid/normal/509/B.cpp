//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,k,a[111];
vector<pair<int,int> >ans[111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=k;i++)
    {
        int mn=a[1];
        for(int j=1;j<=n;j++)mn=min(mn,a[j]);
        for(int j=1;j<=n;j++)
        {
            int tmp=min(a[j],mn+1);
            if(tmp>0)ans[j].PB(MP(i,tmp));
            a[j]-=tmp;
        }
    }
    bool ok=1;
    for(int j=1;j<=n;j++)if(a[j]>0)ok=0;
    if(ok)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<ans[i].size();j++)
            {
                for(int _=0;_<ans[i][j].SS;_++)
                {
                    cout<<ans[i][j].FF<<" ";
                }
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}