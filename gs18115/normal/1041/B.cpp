#include<iostream>
using namespace std;
typedef long long LL;
LL gcd(LL x,LL y)
{
    return y==0?x:gcd(y,x%y);
}
LL A,B,X,Y,G;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>A>>B>>X>>Y;
    G=gcd(X,Y);
    X/=G;
    Y/=G;
    cout<<min(A/X,B/Y)<<endl;
    return 0;
}