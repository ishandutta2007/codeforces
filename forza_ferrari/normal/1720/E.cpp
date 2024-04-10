#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[501][501],cnt[300001],sum;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            if(!cnt[a[i][j]]++)
                ++sum;
        }
    if(sum<=m)
    {
        cout<<m-sum<<'\n';
        return 0;
    }
    for(int k=1;k<=n;++k)
    {
        int l=k,r=k;
        for(;r<=n;++r)
        {
            for(int i=l;i<=r;++i)
                if(!--cnt[a[i-k+1][r]])
                    --sum;
            for(int i=l;i<r;++i)
                if(!--cnt[a[r-k+1][i]])
                    --sum;
            while(l<=r&&sum<m-1)
            {
                for(int i=l;i<=r;++i)
                    if(!cnt[a[i-k+1][l]]++)
                        ++sum;
                for(int i=l+1;i<=r;++i)
                    if(!cnt[a[l-k+1][i]]++)
                        ++sum;
                ++l;
            }
            if(sum==m-1||sum==m)
            {
                cout<<"1\n";
                return 0;
            }
        }
        for(;l<=n;++l)
        {
            for(int i=l;i<=n;++i)
                if(!cnt[a[i-k+1][l]]++)
                    ++sum;
            for(int i=l+1;i<=n;++i)
                if(!cnt[a[l-k+1][i]]++)
                    ++sum;
        }
        l=k,r=k;
        for(;r<=n;++r)
        {
            for(int i=l;i<=r;++i)
                if(!--cnt[a[r][i-k+1]])
                    --sum;
            for(int i=l;i<r;++i)
                if(!--cnt[a[i][r-k+1]])
                    --sum;
            while(l<=r&&sum<m-1)
            {
                for(int i=l;i<=r;++i)
                    if(!cnt[a[l][i-k+1]]++)
                        ++sum;
                for(int i=l+1;i<=r;++i)
                    if(!cnt[a[i][l-k+1]]++)
                        ++sum;
                ++l;
            }
            if(sum==m-1||sum==m)
            {
                cout<<"1\n";
                return 0;
            }
        }
        for(;l<=n;++l)
        {
            for(int i=l;i<=n;++i)
                if(!cnt[a[l][i-k+1]]++)
                    ++sum;
            for(int i=l+1;i<=n;++i)
                if(!cnt[a[i][l-k+1]]++)
                    ++sum;
        }
    }
    cout<<"2\n";
    return 0;
}