#include<iostream>
using namespace std;
typedef long long LL;
LL N,K;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    cout<<(N+K-1)/N;
    return 0;
}