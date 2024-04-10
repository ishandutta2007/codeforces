#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,M,i,j;
LL S11[1234],S12[1234],S21[1234],S22[1234];
LL A[1234][1234],B[1234][1234];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cin>>A[i][j];
            if(A[i][j]==1)
            {
                S11[i]++;
                S12[j]++;
            }
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            cin>>B[i][j];
            if(B[i][j]==1)
            {
                S21[i]++;
                S22[j]++;
            }
        }
    }
    for(i=0;i<N;i++)
        if((S11[i]^S21[i])&1)
            return cout<<"NO"<<endl,0;
    for(i=0;i<M;i++)
        if((S12[i]^S22[i])&1)
            return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    return 0;
}