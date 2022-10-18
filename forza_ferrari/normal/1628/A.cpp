#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
int t,n,a[200001];
set<int> s[200001];
vector<int> ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans.clear();
        for(int i=0;i<=n;++i)
            s[i].clear();
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            s[a[i]].insert(i);
        }
        int pos=1,maxn=1;
        while(pos<=n)
        {
            maxn=pos;
            for(int i=0;i<=n;++i)
            {
                if(s[i].lower_bound(pos)==s[i].end())
                {
                    ans.push_back(i);
                    break;
                }
                maxn=max(maxn,*s[i].lower_bound(pos));
            }
            pos=maxn+1;
        }
        cout<<ans.size()<<'\n';
        for(int i:ans)
            cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}