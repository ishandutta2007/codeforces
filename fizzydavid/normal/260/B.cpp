#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
const int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int stoi(string s)
{
    int ans=0;
    for(int i=0;i<s.size();i++)ans=ans*10+s[i]-'0';
    return ans;
}
string s;
map<string,int>mp;
int main()
{
    cin>>s;
    int mxv=0;
    string mx="";
    for(int i=0;i<=s.size()-10;i++)
    {
        if(s[i+2]=='-'&&s[i+5]=='-')
        {
            bool ok=1;int cnt;for(int j=0;j<10;j++)if((s[i+j]<'0'||s[i+j]>'9')&&(j!=2&&j!=5)){ok=0;break;}
            int d=stoi(s.substr(i,2)),m=stoi(s.substr(i+3,2)),y=stoi(s.substr(i+6,4));
            if(ok&&y>=2013&&y<=2015&&m>=1&&m<=12&&d>=1&&d<=day[m])
            {
                mp[s.substr(i,10)]++;
                if(mp[s.substr(i,10)]>mxv)mxv=mp[s.substr(i,10)],mx=s.substr(i,10);
            }
        }
    }
    cout<<mx;
    return 0;
}