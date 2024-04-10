//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
struct Value
{
    int v,pos;
    bool operator<(Value tmp)const
    {
        return v<tmp.v;
    }
}b[1049000];
int num[1049000],a[1049000],n,m,c[1049000];
ll res[2][21];
bool status[20];
void binary1(int l,int r,int power)
{
    if(l==r)return;int mid=(l+r)/2;
    binary1(l,mid,power-1);
    binary1(mid+1,r,power-1);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){if(a[i]>a[j])c[k++]=a[j++],res[0][power]+=mid-i+1;else c[k++]=a[i++];}
    while(i<=mid)c[k++]=a[i++];
    while(j<=r)c[k++]=a[j++];
    for(int i=l;i<=r;i++)a[i]=c[i];
}
void binary2(int l,int r,int power)
{
    if(l==r)return;int mid=(l+r)/2;
    binary2(l,mid,power-1);
    binary2(mid+1,r,power-1);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){if(a[i]<a[j])c[k++]=a[j++],res[1][power]+=mid-i+1;else c[k++]=a[i++];}
    while(i<=mid)c[k++]=a[i++];
    while(j<=r)c[k++]=a[j++];
    for(int i=l;i<=r;i++)a[i]=c[i];
}
void init()
{
    for(int i=1;i<=(1<<n);i++)a[i]=num[i];binary1(1,(1<<n),n);
    for(int i=1;i<=(1<<n);i++)a[i]=num[i];binary2(1,(1<<n),n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=(1<<n);i++)
    {
        cin>>b[i].v;b[i].pos=i;
    }
    sort(b+1,b+(1<<n)+1);
    int Last=0,lastr=0;
    for(int i=1;i<=(1<<n);i++)
    {
        if(Last!=b[i].v)Last=b[i].v,lastr=i;
        num[b[i].pos]=lastr;
    }
//  for(int i=1;i<=(1<<n);i++)cout<<a[i]<<" ";cout<<endl;
    init();
//  for(int i=0;i<=n;i++)cout<<res[0][i]<<" "<<res[1][i]<<endl;
    cin>>m;int q;
    ll ans;
    while(m--)
    {
        ans=0;
        cin>>q;
        for(int i=0;i<=q;i++)status[i]=!status[i];
        for(int i=0;i<=n;i++)ans+=res[status[i]][i];
        cout<<ans<<endl;
    }
    return 0;
}