#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
int t,n;
string s;
map<pair<char,char>,bool> mp,mp1;
map<pair<char,pair<char,char> >,bool> mp2;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        mp.clear();
        mp1.clear();
        mp2.clear();
        bool flag=0;
        while(n--)
        {
            cin>>s;
            int len=s.length();
            if(len==1)
                flag=1;
            if(len==2)
            {
                if(mp.count({s[1],s[0]})||mp1.count({s[1],s[0]})||s[0]==s[1])
                    flag=1;
                mp[{s[0],s[1]}]=1;
            }
            if(len==3)
            {
                if(mp.count({s[2],s[1]})||mp2.count({s[2],{s[1],s[0]}})||s[0]==s[2])
                    flag=1;
                mp1[{s[0],s[1]}]=mp2[{s[0],{s[1],s[2]}}]=1;
            }
            
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}