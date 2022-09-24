#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,i,cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    if(N<4)
        return cout<<0<<endl,0;
    for(i=2;i<=N;i++)
    {
        if(N/i<2)
            break;
        cnt+=N/i*i-i;
    }
    cout<<(cnt<<2)<<endl;
    return 0;
}