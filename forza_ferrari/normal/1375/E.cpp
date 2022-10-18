#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[1001],pos[1001];
pair<int,int> tmp[1001];
vector<pair<int,int> > ans;
inline void move(int x,int y)
{
    ans.emplace_back(x,y);
    swap(pos[a[x]],pos[a[y]]);
    swap(a[x],a[y]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        tmp[i].first=a[i];
        tmp[i].second=i;
    }
    sort(tmp+1,tmp+n+1);
    for(int i=1;i<=n;++i)
    {
        a[tmp[i].second]=i;
        pos[i]=tmp[i].second;
    }
    for(int i=1;i<=n;++i)
        for(int j=a[i]-1;j>=i;--j)
            move(i,pos[j]);
    cout<<ans.size()<<'\n';
    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<'\n';
    return 0;
}