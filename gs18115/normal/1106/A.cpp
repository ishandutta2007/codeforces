#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
char S[2345][2345];
inline bool chk(LL x,LL y)
{
    return S[x][y]=='X'&&S[x-1][y-1]=='X'&&S[x-1][y+1]=='X'&&S[x+1][y-1]=='X'&&S[x+1][y+1]=='X';
}
LL N,i,j,cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>S[i];
    for(i=1;i<N-1;i++)
        for(j=1;j<N-1;j++)
            if(chk(i,j))
                cnt++;
    cout<<cnt<<endl;
    return 0;
}