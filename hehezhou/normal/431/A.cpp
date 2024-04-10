#include<bits/stdc++.h>
using namespace std;
string s;
int a1,a2,a3,a4,ans=0;
int main(){
    cin>>a1>>a2>>a3>>a4;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        ans+=a1;
        if(s[i]=='2')
        ans+=a2;
        if(s[i]=='3')
        ans+=a3;
        if(s[i]=='4')
        ans+=a4;
    }
    cout<<ans;
}