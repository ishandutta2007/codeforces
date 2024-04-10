#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL i,j,k,p,y,ans;
bool flag;
vector<LL>prime;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>p>>y;
    if(p>1)
        prime.push_back(p);
    for(i=y;i>max(1LL,y-1234);i--)
    {
        flag=true;
        k=i;
        for(j=2;j*j<=k;j++)
        {
            if(k%j==0)
            {
                if(j<=p)
                {
                    flag=false;
                    break;
                }
                while(k%j==0)
                    k/=j;
            }
        }
        if(k>1&&k<=p)
            flag=false;
        if(flag)
            break;
    }
    if(i<=y-1234||i<=1)
        i=-1;
    cout<<i<<endl;
    return 0;
}