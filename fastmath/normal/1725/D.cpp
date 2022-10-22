#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int r,o;
bool atl(int k1,int l1,int k2,int l2)
{
    int o=min(k1,k2);k1-=o;k2-=o;
    if(k1>30) return true;
    if(k2>30) return false;
    return (1LL<<k1)*(2*l1+1)>=(1LL<<k2)*(2*l2+1);
}
int floor(int x,int y)
{
    if(x<0) return (x-y+1)/y;
    else return x/y;
}
int h(int k)
{
    if(k<0) return 0;
    if(k>=r) return (r+2)*(r+2)/4;
    /*int ans=0;
    for(int i=0;i<=k;++i)
    {
        ans+=(floor((r-i),2)+1);
    }
    return ans;*/
    return (r+2)*(r+2)/4-(r+2-k-1)*(r+2-k-1)/4;
}
int g(int k,int l)
{
    int ans=0;
    for(int k1=max(0LL,k-30);k1<=k+30;++k1)
    {
        int upl=(r+k1)/2-k1+1;
        if(upl<0) continue;
        int h=min(k,k1);
        int o1=k-h;int o2=k1-h;
        int lmax=((1LL<<o1)*(2*l+1))/(1LL<<o2);
        lmax=(lmax+1)/2;
        ans+=min(upl,lmax);
    }
    ans+=h(k-31);
    return ans;
}
int f(int k,int l)
{
    int upl=o;int lowl=(-1);
    while(upl-lowl>1)
    {
        int midl=(lowl+upl)/2;
        if(atl(k,l,(r+1-2*midl),midl)) upl=midl;
        else lowl=midl;
    }
    return g(k,l)+(o-upl);
}
int f2(int k,int l)
{
    while(l%2==0) {++k;l/=2;}
    return f(k,(l-1)/2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin>>n;
    #ifdef LOCAL
    q=n;
    #else
    cin>>q;
    #endif
    int low=0;int up=1e9;
    while(up-low>1)
    {
        int mid=(low+up)/2;
        int o=(mid+2)*(mid+2)/4;
        if(o>n) up=mid;
        else low=mid;
    }
    r=low;
    o=n-(r+2)*(r+2)/4;
    int sum=n+o*(r+1)+(r+2)*(r+1)*r/6+(r/2)*(r/2+1)/2;
    cout<<sum<<'\n';
    int sum2=0;int kcur=0;
    vector<pair<int,int> > v;
    for(int cyc=1;cyc<=q;++cyc)
    {
        int pos;
        #ifdef LOCAL
        pos=cyc;
        #else
        cin>>pos;
        #endif
        while(f(kcur,0)<pos) ++kcur;
        int kh=max(0LL,kcur-22);
        int lowl=0;int upl=(1LL<<22)+1;
        while(upl-lowl>1)
        {
            int midl=(lowl+upl)/2;
            if(f2(kh,midl)>=pos) upl=midl;
            else lowl=midl;
        }
        int k=kh;int l=upl;
        while(l%2==0) {l/=2;++k;}
        v.push_back({k,(l-1)/2});
        sum2+=(k+l);
        #ifndef LOCAL
        cout<<(k+l)<<'\n';
        #endif
    }
    for(int i=0;i<((int) v.size())-1;++i)
    {
        if(!atl(v[i+1].first,v[i+1].second,v[i].first,v[i].second)) cout<<i<<" i "<<endl;
        assert(atl(v[i+1].first,v[i+1].second,v[i].first,v[i].second));
    }
    cerr<<sum2<<" sum2 "<<endl;
    return 0;
}