#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL S,s,P,N,i;
LL A[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        P=min(A[i]>>1,s);
        S+=P;
        A[i]-=P<<1;
        s-=P;
        S+=A[i]/3;
        A[i]%=3;
        s+=A[i];
    }
    cout<<S<<endl;
    return 0;
}