#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const char c[2]={'R','B'};
int t,n;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        bool flag=1;
        for(register int i=0;i<n;++i)
        {
            if(s[i]!='?')
            {
                if(flag)
                {
                    int tmp=s[i]=='R'? 1:0;
                    for(register int j=i-1;~j;--j)
                    {
                        s[j]=c[tmp];
                        tmp^=1;
                    }
                    flag=0;
                }
                int tmp=s[i]=='R'? 1:0;
                for(register int j=i+1;j<n;++j)
                {
                    if(s[j]!='?')
                    {
                        i=j-1;
                        break;
                    }
                    s[j]=c[tmp];
                    tmp^=1;
                }
            }
        }
        if(flag)
        {
            int tmp=0;
            for(register int i=0;i<n;++i)
            {
                s[i]=c[tmp];
                tmp^=1;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}