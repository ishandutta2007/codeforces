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
int n,k,a[111],sum;
vector<pair<int,int> >ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=k;i++)
    {
        int mx=0,mxi;
        for(int j=1;j<=n;j++)
        {
            if(mx<a[j])mx=a[j],mxi=j;
        }
        int mn=INF,mni;
        for(int j=1;j<=n;j++)
        {
            if(mn>a[j])mn=a[j],mni=j;
        }
        if(sum%n!=0&&mx-mn==1||sum%n==0&&mx-mn==0)break;
        ans.pb(mp(mxi,mni));
        a[mni]++;a[mxi]--;
    }
        int mx=0,mxi;
        for(int j=1;j<=n;j++)
        {
            if(mx<a[j])mx=a[j],mxi=j;
        }
        int mn=INF,mni;
        for(int j=1;j<=n;j++)
        {
            if(mn>a[j])mn=a[j],mni=j;
        }
    cout<<mx-mn<<" "<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].ff<<" "<<ans[i].ss<<endl;
    }
    return 0;
}