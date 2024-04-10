#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
string s1,s2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>k;
    while(k-->0){
        int t=0;
        s2=s1.substr(0,s1.size()-1);
        if(s1[s1.size()-1]!='0')
            s2+=s1[s1.size()-1]-1;
        s1=s2;
        s2="";
    }
    cout<<s1;
}