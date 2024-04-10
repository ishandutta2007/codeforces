#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
char S[123456];
LL T,N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T-->0)
    {
        cin>>N;
        cin>>S;
        if(N>2)
        {
            cout<<"YES\n2\n";
            cout<<S[0]<<' '<<S+1<<'\n';
        }
        else if(S[0]<S[1])
        {
            cout<<"YES\n2\n";
            cout<<S[0]<<' '<<S[1]<<'\n';
        }
        else
            cout<<"NO\n";
    }
    cout<<endl;
    return 0;
}