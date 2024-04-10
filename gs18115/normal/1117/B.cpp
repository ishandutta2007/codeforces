#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,M,K,i;
LL A[234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>K;
    for(i=0;i<N;i++)
        cin>>A[i];
    sort(A,A+N,greater<LL>());
    N=M/++K;
    cout<<A[0]*(M-N)+A[1]*N<<endl;
    return 0;
}