#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL A,B,C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>A>>B>>C;
    if(A>B+1)
        A=B+1;
    if(B>A+1)
        B=A+1;
    cout<<A+B+C*2<<endl;
    return 0;
}