#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,A,x,i,ans;
LL c[1234567][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    c[x][1]++;
    for(i=0;i<N;i++)
    {
        cin>>A;
        x^=A;
        ans+=c[x][i&1];
        c[x][i&1]++;
    }
    cout<<ans<<endl;
    return 0;
}