#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,k,n,ans[100001];
string s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        scanf("%d",&k);
        n=s.length();
        bool flag=1;
        memset(ans,0,sizeof ans);
        for(register int i=0;i<n;++i)
            if(s[i]=='0')
            {
                if(i-k>=0)
                    ans[i-k]=1;
                if(i+k<n)
                    ans[i+k]=1;
            }
        for(register int i=0;i<n;++i)
            if(s[i]=='1')
            {
                if(i-k>=0&&!ans[i-k])
                    continue;
                if(i+k<n&&!ans[i+k])
                    continue;
                puts("-1");
                flag=0;
                break;
            }
        if(!flag)
            continue;
        for(register int i=0;i<n;++i)
            putchar(ans[i]? '0':'1');
        puts("");
    }
    return 0;
}