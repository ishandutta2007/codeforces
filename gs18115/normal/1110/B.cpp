#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,M,K,i,ans;
LL A[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>K;
    for(i=0;i<N;i++)
        cin>>A[i];
    ans=A[N-1]-A[0]+1;
    for(i=N;--i>0;)
        A[i]=A[i]-A[i-1]-1;
    sort(A+1,A+N,greater<LL>());
    for(i=1;i<K;i++)
        ans-=A[i];
    cout<<ans<<endl;
    return 0;
}