#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL D[234567];
char S[234567];
LL N,K,i,j,ans;
vector<LL>V;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    for(i=0;i<N;i++)
        cin>>D[i];
    cin>>S;
    V.push_back(D[0]);
    for(i=1;i<N;i++)
    {
        if(S[i]!=S[i-1])
        {
            sort(V.begin(),V.end(),greater<LL>());
            for(j=0;j<min((LL)V.size(),K);j++)
                ans+=V[j];
            V.clear();
        }
        V.push_back(D[i]);
    }
    sort(V.begin(),V.end(),greater<LL>());
    for(i=0;i<min((LL)V.size(),K);i++)
        ans+=V[i];
    V.clear();
    cout<<ans<<endl;
    return 0;
}