#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL A,B,C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>A>>B>>C;
    A+=2;
    B+=1;
    cout<<min({A,B,C})*3-3<<endl;
    return 0;
}