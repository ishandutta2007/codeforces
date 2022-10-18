#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> a[250001],ans[250001],num,p;
inline bool check()
{
    for(register int i=1;i<=n;++i)
    {
        int res=0;
        for(register int j=0;j<m;++j)
            if(a[i][j]^num[j])
                ++res;
        if(res>2)
            return 0;
    }
    return 1;
}
void dfs(int k)
{
    if(k==m)
    {
        if(check())
        {
            puts("Yes");
            for(register int i=0;i<m;++i)
                printf("%d ",num[i]);
            puts("");
            exit(0);
        }
        return;
    }
    for(register int i=0;i<(int)(ans[k].size());++i)
    {
        num.push_back(ans[k][i]);
        dfs(k+1);
        num.pop_back();
    }
}
inline void solve()
{
    for(register int i=0;i<3;++i)
        for(register int j=0;j<3;++j)
        {
            if(i==j)
                continue;
            vector<int> tmp;
            for(register int k=0;k<m;++k)
                if(k==p[j])
                    tmp.push_back(ans[k][1]);
                else
                    if(k==p[i])
                        tmp.push_back(-1);
                    else
                        tmp.push_back(ans[k][0]);
            bool flag=1;
            for(register int l=1;l<=n;++l)
            {
                int res=0;
                for(register int r=0;r<m;++r)
                {
                    if(tmp[r]==-1)
                        continue;
                    if(a[l][r]^tmp[r])
                        ++res;
                }
                if(res>2)
                {
                    flag=0;
                    break;
                }
                if(tmp[p[i]]==-1&&res==2)
                    tmp[p[i]]=a[l][p[i]];
            }
            if(flag)
            {
                puts("Yes");
                for(register int k=0;k<m;++k)
                    printf("%d ",tmp[k]==-1? ans[k][0]:tmp[k]);
                puts("");
                exit(0);
            }
        }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
        {
            int x;
            scanf("%d",&x);
            a[i].push_back(x);
        }
    for(register int i=0;i<m;++i)
        ans[i].push_back(a[1][i]);
    for(register int i=2;i<=n;++i)
    {
        int res=0;
        for(register int j=0;j<m;++j)
            if(a[1][j]^a[i][j])
                ++res;
        if(res<=2)
            continue;
        if(res>4)
        {
            puts("No");
            return 0;
        }
        if(res==4)
        {
            for(register int j=0;j<m;++j)
                if(a[1][j]^a[i][j])
                    ans[j].push_back(a[i][j]);
            dfs(0);
            puts("No");
            return 0;
        }
    }
    for(register int i=2;i<=n;++i)
    {
        int res=0;
        for(register int j=0;j<m;++j)
            if(a[1][j]^a[i][j])
                ++res;
        if(res==3)
        {
            for(register int j=0;j<m;++j)
                if(a[1][j]^a[i][j])
                {
                    ans[j].push_back(a[i][j]);
                    p.push_back(j);
                }
            solve();
            puts("No");
            return 0;
        }
    }
    dfs(0);
    puts("No");
    return 0;
}