#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MAXN=2e5+10;
map<LL,LL>M;
vector<PL>V;
LL N,i,j,A;
LL t,T,R;
LL maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>i;
    for(i=0;i<N;i++)
    {
        cin>>A;
        V.push_back({A,0});
    }
    cin>>N>>i;
    for(i=0;i<N;i++)
    {
        cin>>A;
        V.push_back({A,1});
    }
    sort(V.begin(),V.end());
    N=V.size();
    maxi=2;
    for(i=0;i<31;i++)
    {
        M.clear();
        R=1LL<<i;
        for(j=0;j<N;j++)
        {
            t=(V[j].first+V[j].second*R)%(R<<1);
            T=M[t]+1;
            maxi=max(maxi,T);
            M[t]=T;
        }
    }
    cout<<maxi<<endl;
    return 0;
}