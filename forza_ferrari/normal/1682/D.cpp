#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int t,n;
string s;
vector<pair<int,int> > ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int cnt=0;
        for(int i=0;i<n;++i)
            cnt+=s[i]-'0';
        if(!cnt||(cnt&1))
        {
            cout<<"NO\n";
            continue;
        }
        if(cnt==n)
        {
            cout<<"YES\n";
            for(int i=2;i<=n;++i)
                cout<<"1 "<<i<<'\n';
            continue;
        }
        ans.clear();
        int pos=-1;
        for(int i=0;i<n;++i)
            if(s[i]=='1'&&s[(i+1)%n]=='0')
            {
                pos=(i+1)%n;
                break;
            }
        int p=(pos+1)%n,lst=p;
        while(p!=pos)
        {
            if(s[p]=='1')
            {
                ans.emplace_back(lst,pos);
                for(int i=lst;i!=p;i=(i+1)%n)
                    ans.emplace_back(i,(i+1)%n);
                lst=(p+1)%n;
            }
            p=(p+1)%n;
        }
        cout<<"YES\n";
        for(auto i:ans)
            cout<<i.first+1<<" "<<i.second+1<<'\n';
    }
    return 0;
}