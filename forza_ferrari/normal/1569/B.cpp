#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,ans[51][51],lst,fst,cnt;
string s;
bool flag;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(register int i=1;i<=n;++i)
            for(register int j=1;j<=n;++j)
                ans[i][j]=0;
        cin>>s;
        s=" "+s;
        flag=1;
        fst=lst=cnt=0;
        for(register int i=1;i<=n;++i)
        {
            if(s[i]=='1')
            {
                for(register int j=1;j<=n;++j)
                    if(ans[i][j]==-1)
                    {
                        puts("NO");
                        flag=0;
                        break;
                    }
            }
            else
            {
                ++cnt;
                if(!fst)
                    fst=i;
                if(lst)
                {
                    ans[lst][i]=1;
                    ans[i][lst]=-1;
                }
                lst=i;
            }
            if(!flag)
                break;
        }
        if(!flag)
            continue;
        if(cnt&&cnt<=2)
        {
            puts("NO");
            continue;
        }
        if(fst)
        {
            ans[lst][fst]=1;
            ans[fst][lst]=-1;
        }
        puts("YES");
        for(register int i=1;i<=n;++i,puts(""))
            for(register int j=1;j<=n;++j)
                putchar(i==j? 'X':ans[i][j]? ans[i][j]>0? '+':'-':'=');
    }
    return 0;
}