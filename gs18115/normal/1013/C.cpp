#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MAXI=1234567;
const LL INF=1LL<<55LL;
LL i,N;
LL A[MAXI];
LL mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(i=0;i<N<<1;i++)
        cin>>A[i];
    sort(A,A+(N<<1));
    mini=(A[N-1]-A[0])*(A[N*2-1]-A[N]);
    for(i=0;i<=N;i++)
        if(mini>(A[i+N-1]-A[i])*(A[N*2-1]-A[0]))
            mini=(A[i+N-1]-A[i])*(A[N*2-1]-A[0]);
    cout<<mini;
    return 0;
}