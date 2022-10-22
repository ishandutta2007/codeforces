#include<iostream>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 200001
int N,M,p[MAXN],mul[MAXN],sum[MAXN],ans;bool is[MAXN];set<int>s;
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int calc(int l,int r){return 1ll*(0ll+mul[l-1]+sum[r-2]-sum[l-1]+P)*pow(mul[r-1],P-2)%P;}
int main()
{
	cin>>N>>M;For(i,1,N)cin>>p[i],p[i]=1ll*p[i]*pow(100,P-2)%P;mul[0]=1;For(i,1,N)mul[i]=1ll*mul[i-1]*p[i]%P,sum[i]=(sum[i-1]+mul[i])%P;is[1]=1;s.insert(1);s.insert(N+1);ans=calc(1,N+1);
	For(i,1,M){int x;cin>>x;if(is[x]){int l=*(--s.lower_bound(x)),r=*s.upper_bound(x);ans=(ans-calc(l,x)-calc(x,r)+calc(l,r)+0ll+P+P)%P;s.erase(x);is[x]=0;}else{int l=*(--s.lower_bound(x)),r=*s.upper_bound(x);ans=(ans+0ll+calc(l,x)+calc(x,r)-calc(l,r)+P)%P;s.insert(x);is[x]=1;}cout<<ans<<endl;}return 0;
}