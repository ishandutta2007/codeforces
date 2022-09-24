#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL A,B,C,X,Y,Z;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>X>>Y>>Z;
    cin>>A>>B>>C;
    cout<<(A>=X&&A+B>=X+Y&&A+B+C>=X+Y+Z?"YES":"NO")<<endl;
    return 0;
}