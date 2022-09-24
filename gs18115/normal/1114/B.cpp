#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,M,K,i,ans,cnt;
LL A[1234567];
vector<LL>V2;
vector<PL>V;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>K;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
        V.emplace_back(A[i],i);
    sort(V.begin(),V.end(),greater<PL>());
    V.erase(V.begin()+M*K,V.end());
    for(i=0;i<M*K;i++)
        ans+=V[i].first;
    for(i=0;i<M*K;i++)
        V2.push_back(V[i].second);
    sort(V2.begin(),V2.end());
    cout<<ans<<endl;
    for(i=0;i<N;i++)
    {
        if(*lower_bound(V2.begin(),V2.end(),i)==i)
        {
            cnt++;
            if(cnt>M)
            {
                cout<<i<<' ';
                cnt-=M;
            }
        }
    }
    cout<<endl;
    return 0;
}