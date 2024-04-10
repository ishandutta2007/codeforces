#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        if(n>=2&&s[0]==s[1])
        {
            cout<<s[0]<<s[0]<<'\n';
            continue;
        }
        for(int i=0;i<n;++i)
        {
            if(i==n-1||s[i]<s[i+1])
            {
                for(int j=0;j<=i;++j)
                    cout<<s[j];
                for(int j=i;j>=0;--j)
                    cout<<s[j];
                cout<<'\n';
                break;
            }
        }
    }
    return 0;
}