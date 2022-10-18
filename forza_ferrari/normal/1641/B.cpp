#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int t,n;
vector<pair<int,int> > ans;
vector<int> st,sum,s;
map<int,int> cnt;
int main()
{
    cin>>t;
    while(t--)
    {
        ans.clear();
        st.clear();
        sum.clear();
        cnt.clear();
        s.clear();
        cin>>n;
        int pos=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            s.emplace_back(x);
            ++cnt[x];
        }
        for(int i=0;i<(int)s.size();++i)
        {
            if(st.empty())
            {
                st.emplace_back(s[i]);
                continue;
            }
            if(s[i]!=st[0])
            {
                st.emplace_back(s[i]);
                continue;
            }
            int tot=0;
            sum.emplace_back(st.size()<<1);
            for(int j=1;j<(int)st.size();++j)
            {
                ++i;
                ans.push_back({i,st[j]});
                s.insert(s.begin()+i,st[j]);
                s.insert(s.begin()+i,st[j]);
            }
            st.clear();
        }
        bool flag=1;
        for(auto i:cnt)
            if(i.second&1)
            {
                puts("-1");
                flag=0;
                break;
            }
        if(!flag)
            continue;
        cout<<ans.size()<<'\n';
        for(auto i:ans)
            cout<<i.first<<" "<<i.second<<'\n';
        cout<<sum.size()<<'\n';
        for(int i:sum)
            cout<<i<<' ';
        cout<<'\n';
    }
    return 0;
}