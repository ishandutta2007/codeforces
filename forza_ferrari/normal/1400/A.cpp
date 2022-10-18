#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
int t,n,sum,ans[101];
string s;
signed main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s;
        for(register int i=1;i<=n;++i)
        {
            ans[i-1]=(s[(i<<1)-2]=='1');
            putchar(ans[i-1]+'0');
        }
        puts("");
    }
    return 0;
}