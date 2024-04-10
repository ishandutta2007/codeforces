#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100001],cnt[31],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        int w=a[i],tot=0;
        while(w)
        {
            w>>=1;
            ++tot;
        }
        ++cnt[tot-1];
    }
    for(int i=0;i<=30;++i)
        if(cnt[i]>2)
        {
            cout<<"1\n";
            return 0;
        }
    ans=1e9;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
            for(int k=j+1;k<=n;++k)
            {
                int l=0,r=0;
                for(int p=i;p<=j;++p)
                    l^=a[p];
                for(int p=j+1;p<=k;++p)
                    r^=a[p];
                if(l>r)
                    ans=min(ans,k-i-1);
            }
    cout<<(ans==1e9? -1:ans)<<'\n';
    return 0;
}