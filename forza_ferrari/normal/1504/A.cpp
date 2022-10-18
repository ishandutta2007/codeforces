#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t;
string s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        bool flag=0;
        int n=s.length();
        for(register int i=0;i<n;++i)
            if(s[i]!='a')
            {
                puts("YES");
                for(register int j=0;j<n-i;++j)
                    putchar(s[j]);
                putchar('a');
                for(register int j=n-i;j<n;++j)
                    putchar(s[j]);
                puts("");
                flag=1;
                break;
            }
        if(flag)
            continue;
        puts("NO");
    }
    return 0;
}