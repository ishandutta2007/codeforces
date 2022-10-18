#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,a[200001],ans[200001],sum,pre[200001][2],lst[2],num[200001],cnt;
bool vis[200001];
void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
int find(int k,int f)
{
    if(!k)
        return 0;
    if(!vis[k])
    {
        vis[k]=1;
        return k;
    }
    return pre[k][f]=find(pre[k][f],f);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        lst[0]=lst[1]=0;
        sum=n;
        cnt=0;
        for(register int i=1;i<=n;++i)
        {
            char c=getchar();
            while(c!='0'&&c!='1')
                c=getchar();
            a[i]=c-'0';
            pre[i][a[i]^1]=lst[a[i]^1];
            pre[i][a[i]]=lst[a[i]];
            lst[a[i]]=i;
            ans[i]=i;
        }
        for(register int i=2;i<=n;++i)
        {
            int node=find(pre[i][a[i]^1],a[i]^1);
            if(node)
            {
                --sum;
                ans[i]=ans[node];
            }
        }
        print(sum);
        puts("");
        for(register int i=1;i<=n;++i)
        {
            pre[i][0]=pre[i][1]=vis[i]=0;
            if(!num[ans[i]])
                num[ans[i]]=++cnt;
            print(num[ans[i]]);
            putchar(' ');
        }
        for(register int i=1;i<=n;++i)
            num[i]=0;
        puts("");
    }
    return 0;
}