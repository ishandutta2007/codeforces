#include<iostream>
using namespace std;
typedef long long LL;
LL N,L,A,i,T,X,PT,sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>L>>A;
    PT=0;
    for(i=1;i<=N;i++)
    {
        cin>>T>>X;
        sum+=(T-PT)/A;
        PT=T+X;
    }
    sum+=(L-PT)/A;
    cout<<sum<<endl;
    return 0;
}