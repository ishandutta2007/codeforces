#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int k,p;
vector<int> ans;
signed main()
{
    cin>>p>>k;
    while(p)
    {
        ans.emplace_back(p%(-k));
        p/=-k;
        if(ans.back()<0)
        {
            ans.back()+=k;
            ++p;
        }
    }
    cout<<ans.size()<<'\n';
    for(int i:ans)
        cout<<i<<' ';
    cout<<'\n';
    return 0;
}