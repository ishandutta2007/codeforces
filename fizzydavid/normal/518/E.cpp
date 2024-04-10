//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const int INF=2147483647;
const ll LINF=1ll<<61;
int n,k;
ll a[100111],pre[100111],nxt[100111];
bool que[100111];
inline ll getval(bool &bol)
{
    ll __res=0;bool __neg=0;
    char __c;__c=getchar();
    while(__c==' '||__c=='\n')__c=getchar();
    if(__c=='?')
    {
        bol=1;
        return 0;
    }
    while(__c!=' '&&__c!='\n')
    {
        if(__c=='-')__neg=1;
        else __res=__res*10+__c-'0';
        __c=getchar();
    }
    if(__neg)__res=-__res;
    return __res;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)a[i]=getval(que[i]);
    for(int i=1;i<=n;i++)
    {
        if(i>k)
        {
            if(!que[i-k])pre[i]=a[i-k];else pre[i]=pre[i-k];
        }else pre[i]=-INF;
    }
    for(int i=n;i>=1;i--)
    {
        if(i+k<=n)
        {
            if(!que[i+k])nxt[i]=a[i+k];else nxt[i]=nxt[i+k];
        }else nxt[i]=INF;
    }
    for(int i=1;i<=n;i++)
    {
        if(que[i])
        {
            int j=i,l=j,r=j,cnt=0;
            while(j<=n&&que[j])que[j]=0,r=j,j+=k,cnt++;
            int mid=l+cnt/2*k;
            if(ll(nxt[l]-pre[l]-1)<cnt)
            {
                puts("Incorrect sequence");
                return 0;
            }
            a[mid]=max(min(nxt[i]-1-(cnt-1)/2,0ll),pre[i]+1+cnt/2);
//          cout<<l<<" "<<r<<" "<<mid<<" "<<cnt<<" "<<a[mid]<<endl;
            for(j=mid-k;j>=l;j-=k)a[j]=a[j+k]-1;
            for(j=mid+k;j<=r;j+=k)a[j]=a[j-k]+1;
        }
    }
    for(int i=k+1;i<=n;i++)
    {
        if(a[i-k]>=a[i])
        {
            puts("Incorrect sequence");
            return 0;
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}