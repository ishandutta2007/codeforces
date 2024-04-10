#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N,a[MAXN][MAXN],cnt,b[MAXN],sum[MAXN];
int main()
{
	cin>>N;For(i,1,N)cin>>b[i];int tot=0;FOR(k,N,1)For(i,1,N)if(b[i]==k){int x=tot++;For(j,1,b[i]){a[i][x]=1;x=(x+1)%(N+1);}}
	For(j,0,N){For(i,1,N)sum[j]+=a[i][j];if(sum[j])cnt++;}cout<<cnt<<endl;For(j,0,N)if(sum[j]){For(i,1,N)cout<<a[i][j];cout<<endl;}return 0;
}