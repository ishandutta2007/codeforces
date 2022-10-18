#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<int> v[2];
vector<pair<int,int> > ans;
int main()
{
    cin>>n;
    cout<<"? 1"<<endl;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        v[x&1].emplace_back(i);
        if(x==1)
            ans.emplace_back(1,i);
    }
    if(v[0].size()<=v[1].size())
    {
        for(auto i:v[0])
        {
            if(i==1)
                continue;
            cout<<"? "<<i<<endl;
            for(int j=1;j<=n;++j)
            {
                int x;
                cin>>x;
                if(j==1)
                    continue;
                if(x==1)
                    ans.emplace_back(i,j);
            }
        }
    }
    else
    {
        for(auto i:v[1])
        {
            cout<<"? "<<i<<endl;
            for(int j=1;j<=n;++j)
            {
                int x;
                cin>>x;
                if(j==1)
                    continue;
                if(x==1)
                    ans.emplace_back(i,j);
            }
        }
    }
    cout<<"!"<<endl;
    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<endl;
    return 0;
}