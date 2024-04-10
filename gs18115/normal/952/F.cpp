#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL ans,i,j,D;
char S[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>ans;
    cin>>S;
    for(i=0;S[i]>0;)
    {
        j=i;
        D=S[j++]-'0';
        while(S[j]>='0')
            D=D*10+S[j++]-'0';
        ans+=D*(44-S[i]);
        i=j;
    }
    cout<<ans<<endl;
    return 0;
}