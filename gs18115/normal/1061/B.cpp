#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,M,S,i,P;
LL A[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        S+=A[i];
    }
    sort(A,A+N,greater<LL>());
    for(i=0;i<N;i++)
    {
        if(A[i+1]>A[i])
            A[i+1]=A[i]-1;
        if(A[i+1]==A[i]&&A[i]>0)
            A[i+1]--;
        P+=max(1LL,A[i]-A[i+1]);
    }
    cout<<S-P<<endl;
    return 0;
}