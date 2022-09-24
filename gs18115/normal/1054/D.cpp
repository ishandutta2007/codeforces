#include<iostream>
#include<map>
using namespace std;
typedef long long LL;
map<LL,LL>M;
LL S,N,i,K,A;
LL ans;
LL MAX;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    S=0;
    M[0]++;
    MAX=(1<<K)-1;
    for(i=0;i<N;i++)
    {
        cin>>A;
        S^=A;
        M[min(S,MAX^S)]++;
    }
    for(pair<LL,LL>I:M)
        ans+=(I.second>>1)*(I.second-2>>1)+(I.second+1>>1)*(I.second-1>>1)>>1;
    cout<<N*(N+1)/2-ans<<endl;
    return 0;
}