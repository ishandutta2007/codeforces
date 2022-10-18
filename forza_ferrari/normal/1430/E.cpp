#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
string s;
int n,ans,a[200001],b[200001];
vector<int> v[31];
void qqsort(int l,int r)
{
    if(l==r)
        return;
    int mid=(l+r)>>1;
    qqsort(l,mid);
    qqsort(mid+1,r);
    int i=l,j=mid+1,cnt=l-1;
    while(i<=mid&&j<=r)
        if(a[i]<=a[j])
            b[++cnt]=a[i++];
        else
        {
            ans+=mid-i+1;
            b[++cnt]=a[j++];
        }
    while(i<=mid)
        b[++cnt]=a[i++];
    while(j<=r)
        b[++cnt]=a[j++];
    for(register int i=l;i<=r;++i)
        a[i]=b[i];
}
signed main()
{
    scanf("%lld",&n);
    cin>>s;
    s=" "+s;
    for(register int i=1;i<=n;++i)
        v[s[i]-'a'].push_back(i);
    for(register int i=0;i<26;++i)
        for(register int j=0;j<(int)v[i].size();++j)
            a[v[i][j]]=v[i][v[i].size()-j-1];
    for(register int i=1;i<=n;++i)
        a[i]=n-a[i]+1;
    //for(register int i=1;i<=n;++i)
        //cout<<a[i]<<endl;
    qqsort(1,n);
    printf("%lld\n",ans);
    return 0;
}