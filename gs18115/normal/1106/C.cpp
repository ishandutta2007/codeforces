#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,S,i,j;
LL A[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    sort(A,A+N);
    if(N&1)
    {
        S=(A[0]+A[1]+A[2])*(A[0]+A[1]+A[2]);
        for(i=3;i<(j=N-i+2);i++)
            S+=(A[i]+A[j])*(A[i]+A[j]);
    }
    else
    {
        S=0;
        for(i=0;i<(j=N-i-1);i++)
            S+=(A[i]+A[j])*(A[i]+A[j]);
    }
    cout<<S<<endl;
    return 0;
}