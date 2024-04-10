#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
using namespace std;
string s,s2;
int main()
{
    int i;
    cin>>s;
    for(i=1;i<=s.size();i++)s2+=s[i];
    if(s2.find("at")<s2.size()){s.replace(s2.find("at")+1,2,"@");s2.replace(s2.find("at"),2,"@");}
    while(s2.find("dot")<(s2.size()-4))
    {
        s.replace(s2.find("dot")+1,3,".");
        s2.replace(s2.find("dot"),3,".");
    }
    cout<<s;
    return 0;
}