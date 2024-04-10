#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL i,N,a,b,as,bs;
LL A[1234567],B[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    for(i=0;i<N;i++)
        cin>>B[i];
    sort(A,A+N,greater<int>());
    sort(B,B+N,greater<int>());
    A[N]=B[N]=-INF;
    for(i=0;i<N;i++)
    {
        if(A[a]>B[b])
            as+=A[a++];
        else
            b++;
        if(A[a]>B[b])
            a++;
        else
            bs+=B[b++];
    }
    cout<<as-bs<<endl;
    return 0;
}