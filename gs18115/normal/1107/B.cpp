#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL K,T,X;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T-->0)
    {
        cin>>K>>X;
        cout<<(K-1)*9+X<<'\n';
    }
    cout<<endl;
    return 0;
}