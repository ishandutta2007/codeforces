#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL T,L,R;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T-->0)
    {
        cin>>L>>R;
        cout<<L<<' '<<L*2<<'\n';
    }
    cout<<endl;
    return 0;
}