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
        s=" "+s;
        bool flag=0;
        for(register int i=1;i<n;++i)
            if(s[i]^s[i+1])
            {
                printf("%d %d\n",i,i+1);
                flag=1;
                break;
            }
        if(!flag)
            puts("-1 -1");
    }
    return 0;
}