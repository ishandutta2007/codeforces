#include<bits/stdc++.h>
using namespace std;
int n,i,t,a;
string s;
int main()
{
    cin>>n>>s;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='A')
            a++;
    }
    if((n-a)>a)
        cout<<"Danik\n";
    else if((n-a)<a)
        cout<<"Anton\n";
    else
        cout<<"Friendship\n";
}