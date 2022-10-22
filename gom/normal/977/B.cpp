#include<bits/stdc++.h>
#define N 200005
using namespace std;
string s,ans;
int n,mx;
unordered_map<string,int>dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    for(int i=1;i<s.size();i++){
        string ss;
        ss+=s[i-1];ss+=s[i];
        dp[ss]++;
        if(dp[ss]>mx){
            mx=dp[ss];
            ans=ss;
        }
    }
    cout<<ans;
    return 0;
}