#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<climits>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<list>
#include<queue>
#include<string>
using namespace std;
#define x first
#define y second
#define MP make_pair
#define pb push_back
#define ls k<<1,l,mid
#define rs k<<1|1,mid+1,r
#define LS k<<1
#define RS k<<1|1
#define ll long long
#define lb long double
#define db double
#define PII pair<int,int>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Forn(i,a,b) for(int i=a;i>=b;i--)
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';){if(ch=='-')f=-1;ch=getchar();}
    for(;ch>='0'&&ch<='9';){x=x*10ll+ch-'0';ch=getchar();}
    return x*f;
}
#define MAXN 200010
int n,head,back,que[MAXN];
ll a[MAXN],b[MAXN],sum[MAXN],ans,res;
int main(){
	n=read();
   	For(i,1,n){
        a[i]=read();
        ans+=a[i]*i;b[n-i+1]=a[i];
    }
    head=1;back=0;
    For(i,1,n)sum[i]=sum[i-1]+a[i];
    For(i,1,n){
        for(;head<=back&&a[i]*(n-i)-sum[n]+sum[i]>=a[que[back]]*(n-que[back])-sum[n]+sum[que[back]];)back--;
        que[++back]=i;
        for(;head<back&&a[que[head]]*(i-que[head])-sum[i]+sum[que[head]]<=a[que[head+1]]*(i-que[head+1])-sum[i]+sum[que[head+1]];)head++;
        res=max(res,a[que[head]]*(i-que[head])-sum[i]+sum[que[head]]);
    }
    For(i,1,n)a[i]=b[i];
    head=1;back=0;
    For(i,1,n)sum[i]=sum[i-1]+a[i];
    For(i,1,n){
        for(;head<=back&&sum[n]-sum[i]-a[i]*(n-i)>=sum[n]-sum[que[back]]-a[que[back]]*(n-que[back]);) --back;
        que[++back]=i;
        for(;head<back&&sum[i]-sum[que[head]]-a[que[head]]*(i-que[head])<=sum[i]-sum[que[head+1]]-a[que[head+1]]*(i-que[head+1]);) ++head;
        res=max(res,sum[i]-sum[que[head]]-a[que[head]]*(i-que[head]));
    }printf("%I64d\n",ans+res);
}