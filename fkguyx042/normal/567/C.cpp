#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<algorithm>  
#include<functional>  
#include<iostream>  
#include<cmath>  
#include<cctype>  
#include<ctime>  
#include<map>  
using namespace std;  
#define For(i,n) for(int i=1;i<=n;i++)  
#define Fork(i,k,n) for(int i=k;i<=n;i++)  
#define Rep(i,n) for(int i=0;i<n;i++)  
#define ForD(i,n) for(int i=n;i;i--)  
#define RepD(i,n) for(int i=n;i>=0;i--)  
#define Forp(x) for(int p=pre[x];p;p=next[p])  
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])    
#define Lson (x<<1)  
#define Rson ((x<<1)+1)  
#define MEM(a) memset(a,0,sizeof(a));  
#define MEMI(a) memset(a,127,sizeof(a));  
#define MEMi(a) memset(a,128,sizeof(a));  
#define INF (2139062143)  
#define F (100000007)  
#define MAXN (1000000)  
typedef long long ll;  
ll mul(ll a,ll b){return (a*b)%F;}  
ll add(ll a,ll b){return (a+b)%F;}  
ll sub(ll a,ll b){return (a-b+(a-b)/F*F+F)%F;}  
void upd(ll &a,ll b){a=(a%F+b%F)%F;}  
int n,k;  
int a[MAXN];  
bool b[MAXN]={0};  
int l[MAXN]={0};  
int cnt[40],cnt2[40];  
ll f[MAXN]={0},f2[MAXN]={0};  
map<ll,int> S;   
map<ll,int>::iterator it;   
int main()  
{  
//  freopen("C.in","r",stdin);  
//  freopen(".out","w",stdout);  
      
    scanf("%d%d",&n,&k);  
    For(i,n)  
    {  
        scanf("%d",&a[i]);  
    //  while (a[i]%k==0) l[i]++,a[i]/=k;   
    }  
  
      
    For(i,n)  
    {  
        if (a[i]%k==0&&S.find(a[i]/k)!=S.end()) f[i]=S[a[i]/k];  
  
        it=S.find(a[i]);  
        if (it==S.end()) S[a[i]]=1;  
        else S[a[i]]++;   
          
    }  
    S.clear();  
      
    ForD(i,n)  
    {  
        if (S.find((ll)(a[i])*k)!=S.end()) f2[i]=S[((ll)(a[i])*k)];  
        it=S.find(a[i]);  
        if (it==S.end()) S[a[i]]=1;  
        else S[a[i]]++;   
          
    }  
      
    ll ans=0;  
    For(i,n) ans+=f[i]*f2[i];     
    cout<<ans<<endl;   
  
    return 0;  
}