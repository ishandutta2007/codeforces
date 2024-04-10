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
ll sum[400111][5];
int n,cnt[400111],sz;
int q[100111],a[100111];
bool on[100111];
void update(int id,int l,int r,int pos)
{
    if(l==pos&&r==pos)
    {
        if(on[pos])sum[id][0]=a[pos],cnt[id]=1;
        else sum[id][0]=0,cnt[id]=0;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m)update(id*2,l,m,pos);else update(id*2+1,m+1,r,pos);
    cnt[id]=cnt[id*2]+cnt[id*2+1];
    for(int i=0;i<5;i++)sum[id][i]=sum[id*2][i]+sum[id*2+1][(i-cnt[id*2]%5+5)%5];
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;char op;int x;
    for(int i=1;i<=n;i++)
    {
        cin.ignore();cin>>op;cin.ignore(2);
        if(op!='s')
        {
            cin>>x;a[++sz]=x;
            if(op=='a')q[i]=x;else q[i]=-x;
        }
    }
    sort(a+1,a+sz+1);
    for(int i=1;i<=n;i++)
    {
        if(q[i]==0)cout<<sum[1][2]<<endl;
        else
        {
            int x=(q[i]<0?-q[i]:q[i]),pos=lower_bound(a+1,a+sz+1,x)-a;
            if(q[i]>0)on[pos]=1;
            else on[pos]=0;
            update(1,1,sz,pos);
        }
    }
    return 0;
}