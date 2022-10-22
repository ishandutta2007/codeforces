#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 1001
int T,N,K,a[MAXN],cnt[MAXN],f[MAXN][MAXN];int C(int a,int b){if(!b||b==a)return 1;if(f[a][b])return f[a][b];return f[a][b]=(C(a-1,b-1)+C(a-1,b))%P;}
int main(){cin>>T;while(T--){cin>>N>>K;For(i,1,N)cnt[i]=0;For(i,1,N)cin>>a[i],cnt[a[i]]++;int ans=1;FOR(i,N,1)if(K>cnt[i])K-=cnt[i];else{ans=C(cnt[i],K);break;}cout<<ans<<endl;}return 0;}