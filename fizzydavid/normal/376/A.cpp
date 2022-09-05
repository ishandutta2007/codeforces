#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<set>
using namespace std;
int i,e;
string s,a,b;
int main(){
    long long r=0;
    cin>>s;
    for(i=0;i<s.size();i++)if(s[i]=='^')e=i;
    for(i=0;i<s.size();i++)if(s[i]!='='&&s[i]!='^')r+=(s[i]-'0')*(e-i);
    if(r>0)cout<<"left";
    else if(r<0)cout<<"right";
    else cout<<"balance";
    return 0;
}