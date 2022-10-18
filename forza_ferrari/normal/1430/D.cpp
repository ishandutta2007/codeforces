#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int t,n,ans,ans2,a[200001];
string s;
signed main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s;
        s=" "+s;
        int last=-1,cnt=0,res=0;
        for(register int i=1;i<=n;++i)
        {
            if(last!=s[i])
            {
                if(i!=1)
                    a[++cnt]=res;
                last=s[i];
                res=1;
            }
            else
                ++res;
        }
        a[++cnt]=res;
        ans=ans2=0;
        int l=1;
        for(register int i=1;i<=cnt;++i)
        {
            if(i<l)
                continue;
            if(a[i]!=-1)
            {
                while(a[i]>1&&l<i)
                {
                    if(a[l]==0)
                    {
                        ++l;
                        continue;
                    }
                    --a[i];
                    a[l]=0;
                    ++ans;
                    ++l;
                }
            }
            if(l==i)
                if(a[i]!=1)
                {
                    a[i]=0;
                    ++ans;
                }
        }
        for(register int i=1;i<=cnt;++i)
            if(a[i]==1)
                ++ans2;
        printf("%d\n",ans+(ans2+1)/2);
    }
    return 0;
}