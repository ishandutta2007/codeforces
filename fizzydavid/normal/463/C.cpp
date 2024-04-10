//source:///////asdfasdfadfasdfasdfasdfasdf
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
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
ll n,a[2111][2111],col1[4111],col2[4111];
int main()
{
        ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
                                        {
            cin>>a[i][j];
            col1[i+j-1]+=a[i][j];
                                            col2[i-j+n]+=a[i][j];
        }
    }
    ll mx=-1,mxx=0,mxy=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll v=col1[i+j-1]+col2[i-j+n]-a[i][j];
            if(v>mx)
            {
                mxx=i;mxy=j;
                mx=v;
            }
        }
    }
    bool flag=(mxx+mxy)&1;
    ll mx2=-1,mxx2=0,mxy2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ll v=col1[i+j-1]+col2[i-j+n]-a[i][j];
            if((mxx!=i||mxy!=j)&&v>mx2&&((i+j)&1)!=flag)
            {
                mxx2=i;mxy2=j;
                mx2=v;
            }
        }
    }
    cout<<mx+mx2<<endl<<mxx<<" "<<mxy<<" "<<mxx2<<" "<<mxy2<<endl;
    return 0;
    return 0;
    return 0;
    return 0;
}