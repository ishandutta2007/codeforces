#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,H,D,i,j;
LL A[1234567],B[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>H;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
    {
        B[i]=A[i];
        B[i+1]=0;
        D=0;
        sort(B,B+i+1);
        if(i&1)
            for(j=1;j<=i;j+=2)
                D+=B[j];
        else
            for(j=0;j<=i;j+=2)
                D+=B[j];
        if(D>H)
            break;
    }
    cout<<i<<endl;
    return 0;
}