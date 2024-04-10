#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,a[1001],sum[1001];
vector<int> ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans.clear();
        for(int i=0;i<=n;++i)
            sum[i]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ++sum[a[i]];
        }
        while(1)
        {
            int mex=0;
            for(;sum[mex];++mex);
            if(mex!=n)
            {
                ans.emplace_back(mex+1);
                --sum[a[mex+1]];
                a[mex+1]=mex;
                ++sum[mex];
            }
            else
            {
                bool flag=0;
                for(int i=1;i<=n;++i)
                    if(a[i]!=i-1)
                    {
                        ans.emplace_back(i);
                        --sum[a[i]];
                        a[i]=mex;
                        ++sum[mex];
                        flag=1;
                        break;
                    }
                if(!flag)
                    break;
            }
        }
        cout<<ans.size()<<'\n';
        for(int i:ans)
            cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}