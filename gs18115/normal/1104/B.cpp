#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
string S;
LL i,cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S;
    for(i=1;i<S.size();i++)
    {
        if(S[i]==S[i-1])
        {
            S.erase(i-1,2);
            i-=2;
            cnt++;
        }
    }
    if(cnt&1)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    return 0;
}