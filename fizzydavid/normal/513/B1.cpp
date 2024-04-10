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
int n,m,a[10];
struct value
{
    int v,p[10];
    bool operator<(const value &tmp)const
    {
        if(v>tmp.v)return true;
        else if(v<tmp.v)return false;
        for(int i=1;i<=n;i++)
        {
            if(p[i]<tmp.p[i])return true;
            else if(p[i]>tmp.p[i])return false;
        }
        return false;
    }
}b[40333];
int cal()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int mn=a[i];
            for(int k=i;k<=j;k++)mn=min(mn,a[k]);
            ans+=mn;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int fac=1;
    for(int i=1;i<=n;i++)a[i]=i,fac*=i;
    int id=0;
    do
    {
        id++;
        for(int i=1;i<=n;i++)b[id].p[i]=a[i];
        b[id].v=cal();
    }while(next_permutation(a+1,a+n+1));
    sort(b+1,b+fac+1);
    for(int i=1;i<=n;i++)cout<<b[m].p[i]<<" ";
    return 0;
}