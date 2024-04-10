#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,i,ans;
LL A[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
        if(A[i]!=A[N-1])
            break;
    ans=N-1-i;
    for(i=N;i-->0;)
        if(A[i]!=A[0])
            break;
    cout<<max(ans,i)<<endl;
    return 0;
}