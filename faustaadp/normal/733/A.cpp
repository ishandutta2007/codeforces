#include<bits/stdc++.h>
using namespace std;

int n,i,a=0,x;
string s;

int main()
{
    cin>>s;
    s=s+'A';
    n=s.length();
    for(i=0;i<n;i++)
    {
        a++;
        if((s[i]=='A')||(s[i]=='I')||(s[i]=='U')||(s[i]=='E')||(s[i]=='O')||(s[i]=='Y'))
        {
            x=max(x,a);
          //  cout<<a;
            a=0;
        }
        //cout<<endl;
    }
    cout<<x<<endl;
    return 0;
}