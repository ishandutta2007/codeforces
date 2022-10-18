#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define int long long
int t,n,sum,f[101];
multiset<int> s;
signed main()
{
    f[1]=f[2]=1;
    for(int i=3;i<=60;++i)
        f[i]=f[i-1]+f[i-2];
    cin>>t;
    while(t--)
    {
        s.clear();
        sum=0;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            s.emplace(x);
            sum+=x;
        }
        for(int i=1;i<=60;++i)
        {
            sum-=f[i];
            if(sum<0)
            {
                cout<<"NO\n";
                break;
            }
            if(sum==0)
            {
                int lst=0;
                bool flag=1;
                for(int j=i;j>=1;--j)
                {
                    if(s.empty())
                    {
                        flag=0;
                        break;
                    }
                    int val=*--s.end();
                    s.erase(--s.end());
                    if(lst)
                        s.emplace(lst);
                    if(val<f[j])
                    {
                        flag=0;
                        break;
                    }
                    lst=val-f[j];
                }
                cout<<(flag? "YES":"NO")<<'\n';
                break;
            }
        }
    }
    return 0;
}