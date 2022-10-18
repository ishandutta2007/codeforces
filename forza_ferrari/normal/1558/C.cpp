#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,a[10001];
vector<int> ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(register int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        bool flag=1;
        for(register int i=1;i<=n;++i)
            if((i&1)^(a[i]&1))
            {
                puts("-1");
                flag=0;
                break;
            }
        if(!flag)
            continue;
        ans.clear();
        for(register int i=n;i>=3;i-=2)
        {
            for(register int j=1;j<=i;++j)
                if(a[j]==i)
                {
                    ans.push_back(j);
                    reverse(a+1,a+j+1);
                    break;
                }
            for(register int j=1;j<=i;++j)
                if(a[j]==i-1)
                {
                    ans.push_back(j-1);
                    reverse(a+1,a+j);
                    ans.push_back(j+1);
                    reverse(a+1,a+j+2);
                    ans.push_back(3);
                    reverse(a+1,a+4);
                    ans.push_back(i);
                    reverse(a+1,a+i+1);
                    break;
                }
        }
        printf("%d\n",(int)ans.size());
        for(register int i=0;i<(int)ans.size();++i)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}