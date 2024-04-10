#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,k;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>s;
        if(k==0)
        {
            cout<<1<<endl;
            continue;
        }
        bool flag=1;
        for(int i=0,j=n-1;i<j;++i,--j)
            if(s[i]!=s[j])
            {
                flag=0;
                break;
            }
        cout<<2-flag<<endl;
    }
    return 0;
}