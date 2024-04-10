#include<iostream>
#include<cstdio>
#include<set>
#include<string>
using namespace std;
int n;
bool dp[10001][2];
string str;
set<string> s;
int main()
{
    cin>>str;
    n=str.length();
    for(register int i=n-2;i>=5;--i)
    {
        if(i+2==n)
            dp[i][0]=1;
        if(i+3==n)
            dp[i][1]=1;
        if(dp[i+3][0])
            dp[i][1]=1;
        if(dp[i+2][1])
            dp[i][0]=1;
        if(i+4<=n&&dp[i+2][0]&&str.substr(i,2)!=str.substr(i+2,2))
            dp[i][0]=1;
        if(i+6<=n&&dp[i+3][1]&&str.substr(i,3)!=str.substr(i+3,3))
            dp[i][1]=1;
        if(dp[i][0])
            s.insert(str.substr(i,2));
        if(dp[i][1])
            s.insert(str.substr(i,3));
    }
    cout<<s.size()<<endl;
    for(register set<string>::iterator it=s.begin();it!=s.end();++it)
        cout<<*it<<endl;
    return 0;
}