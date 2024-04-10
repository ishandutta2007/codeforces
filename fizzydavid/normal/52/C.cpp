//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int buk=450;
int n,m,q;
ll a[200111],add[200111],b[200111];
void update(int id)
{
    b[id]=LINF;
    for(int i=id*buk;i<id*buk+buk;i++)b[id]=min(b[id],a[i]);
}
ll query(int l,int r)
{
    ll res=LINF;int i=l;
    while(i%buk!=0&&i<=r)res=min(res,a[i]+add[i/buk]),i++;
    while(i+buk-1<=r)res=min(res,b[i/buk]+add[i/buk]),i+=buk;
    while(i<=r)res=min(res,a[i]+add[i/buk]),i++;
    return res;
}
void inc(int l,int r,int d)
{
    int i=l;
    while(i%buk!=0&&i<=r)a[i]+=d,i++;
    update(l/buk);
    while(i+buk-1<=r)add[i/buk]+=d,i+=buk;
    while(i<=r)a[i]+=d,i++;
    update(r/buk);
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<=(n-1)/buk;i++)update(i);
    cin>>q;int l,r,d;
    while(q--)
    {
        cin>>l>>r;
        if(cin.get()==10)
        {
            if(l<=r)cout<<query(l,r)<<endl;
            else cout<<min(query(0,r),query(l,n-1))<<endl;
        }
        else
        {
            cin>>d;
            if(l<=r)inc(l,r,d);
            else inc(0,r,d),inc(l,n-1,d);
        }
    }
    return 0;
}