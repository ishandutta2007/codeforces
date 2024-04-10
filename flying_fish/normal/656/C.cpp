#include<bits/stdc++.h>
using namespace std;
char n[59];
int ans=0;
int main()
{
    cin>>n;
    for(int i=0;i<=50;i++)
    {
        if(n[i]>'@'&&n[i]<'[')
        ans+=(n[i]-'@');
        if(n[i]>'`'&&n[i]<'{')
        ans-=(n[i]-'`');
    }
    cout<<ans;
}