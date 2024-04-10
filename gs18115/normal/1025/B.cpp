#include<iostream>
using namespace std;
typedef long long LL;
const LL INF=4e15;
LL gcd(LL X,LL Y)
{
    return Y>0?gcd(Y,X%Y):X;
}
LL i,N,g;
LL A[1234567],B[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    g=0;
    for(i=0;i<N;i++)
    {
        cin>>A[i]>>B[i];
        g=gcd(g,A[i]*B[i]);
    }
    if(g==1)
        cout<<-1<<endl;
    else if(g>INF)
    {
        for(i=0;i<N;i++)
        {
            if(g%A[i]==0)
                return cout<<A[i]<<endl,0;
            else if(g%B[i]==0)
                return cout<<B[i]<<endl,0;
        }
    }
    else
    {
        for(i=2;i*i<=g;i++)
            if(g%i==0)
                return cout<<i<<endl,0;
        cout<<g<<endl;
    }
    return 0;
}