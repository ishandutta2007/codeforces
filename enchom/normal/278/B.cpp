#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

string s[35];
int n;
string ans;

int dfs(int k,int d,string ss)
{
    int i;
    if(k==d)
    {
        for(i=1;i<=n;i++) if(s[i].find(ss)!=-1) {  return 0; }
        ans=ss; return 1;
    }
    for(i=0;i<26;i++)
    {
        string sss=ss;
        sss.push_back(i+'a');
        if(dfs(k+1,d,sss)) return 1;
    }
    return 0;
}

int main()
{
    int i;
    cin>>n;
    for(i=1;i<=n;i++) cin>>s[i];
    for(i=1;i<=n;i++)
    {
        string ss="";
        if(dfs(0,i,ss)) 
        {
            cout<<ans<<endl;
            return 0;
        }
    }
}