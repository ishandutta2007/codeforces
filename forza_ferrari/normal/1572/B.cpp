#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,a[200001],sum[200001];
vector<int> ans;
inline void solve(int l,int r)
{
    for(int i=r-2;i>=l;i-=2)
        ans.push_back(i);
    for(int i=l;i<=r-2;i+=2)
        ans.push_back(i);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum[0]=0;
        ans.clear();
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            sum[i]=sum[i-1]^a[i];
        }
        if(sum[n])
        {
            puts("NO");
            continue;
        }
        if(n&1)
        {
            puts("YES");
            solve(1,n);
            cout<<ans.size()<<endl;
            for(auto i:ans)
                cout<<i<<" ";
            cout<<endl;
        }
        else
        {
            bool flag=0;
            for(int i=1;i<=n;i+=2)
                if(!sum[i])
                {
                    flag=1;
                    solve(1,i);
                    solve(i+1,n);
                    break;
                }
            if(!flag)
            {
                puts("NO");
                continue;
            }
            puts("YES");
            cout<<ans.size()<<endl;
            for(auto i:ans)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}