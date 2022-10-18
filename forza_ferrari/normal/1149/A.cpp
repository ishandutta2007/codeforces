#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,cnt[3],sum,a[200001],b[200001],pos;
vector<int> v[3];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ++cnt[a[i]];
        v[a[i]].push_back(i);
    }
    if(cnt[2])
    {
        cout<<"2 ";
        --cnt[2];
    }
    if(cnt[1])
    {
        cout<<"1 ";
        --cnt[1];
    }
    while(cnt[2])
    {
        cout<<"2 ";
        --cnt[2];
    }
    while(cnt[1])
    {
        cout<<"1 ";
        --cnt[1];
    }
    cout<<endl;
    return 0;
}