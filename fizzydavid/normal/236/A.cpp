#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<set>
using namespace std;
string s;
int main()
{
    cin>>s;
    set<char>st;
    for(int i=0;i<s.size();i++)st.insert(s[i]);
    if(st.size()%2)cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";
    return 0;
}