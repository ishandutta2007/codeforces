#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
char S[12],s[12];
int i;
bool flag;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>S;
    for(i=0;i<5;i++)
    {
        cin>>s;
        if(s[0]==S[0]||s[1]==S[1])
            flag=true;
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    return 0;
}