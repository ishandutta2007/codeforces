#include<iostream>
using namespace std;
typedef long long LL;
LL sum(LL X)
{
    LL s=0;
    while(X>0)
    {
        s+=X%10;
        X/=10;
    }
    return s;
}
LL N,M,sum1,sum2,X;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    M=N;
    while(M>0)
    {
        X=X*10+9;
        M/=10;
    }
    X/=10;
    cout<<sum(X)+sum(N-X)<<endl;
    return 0;
}