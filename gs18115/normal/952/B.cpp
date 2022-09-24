#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL i;
string S;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=0;i<6;i++)
    {
        cout<<i<<endl;
        getline(cin,S);
        if(S[0]=='w'||S[0]=='t'||S[0]=='a'||S[2]==' ')
            return cout<<"grumpy"<<endl,0;
    }
    cout<<"normal"<<endl;
    return 0;
}