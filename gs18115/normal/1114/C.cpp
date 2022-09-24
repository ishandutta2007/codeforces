#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,N2,B,i,cnt,ans;
vector<LL>V1,V2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>B;
    for(i=2;i*i<=B;i++)
    {
        if(B%i==0)
        {
            V1.push_back(i);
            cnt=0;
            while(B%i==0)
            {
                cnt++;
                B/=i;
            }
            V2.push_back(cnt);
        }
    }
    if(B!=1)
    {
        V1.push_back(B);
        V2.push_back(1);
    }
    ans=INF;
    for(i=0;i<V1.size();i++)
    {
        N2=N;
        cnt=0;
        while(N2>0)
            cnt+=N2/=V1[i];
        ans=min(ans,cnt/V2[i]);
    }
    cout<<ans<<endl;
    return 0;
}