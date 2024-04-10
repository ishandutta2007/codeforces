#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 60
int N,a[MAXN],pos[MAXN],b[MAXN],cnt,tot[MAXN],num[MAXN][MAXN];
void opt(int x)
{
	if(x&1)
	{
		cnt++;FOR(i,N,N-x+2)num[cnt][++tot[cnt]]=1;num[cnt][++tot[cnt]]=N-x+2-pos[x];if(pos[x]!=1)num[cnt][++tot[cnt]]=pos[x]-1;
		int k=0,sum=0;For(i,1,tot[cnt]){For(j,N-sum-num[cnt][i]+1,N-sum)b[++k]=a[j];sum+=num[cnt][i];}For(i,1,N)pos[a[i]=b[i]]=i;For(i,1,tot[cnt]>>1)swap(num[cnt][i],num[cnt][tot[cnt]-i+1]);
	}
	else
	{
		cnt++;For(i,1,x-1)num[cnt][++tot[cnt]]=1;num[cnt][++tot[cnt]]=pos[x]-x+1;if(pos[x]!=N)num[cnt][++tot[cnt]]=N-pos[x];
		int k=0,sum=0;FOR(i,tot[cnt],1){For(j,N-sum-num[cnt][i]+1,N-sum)b[++k]=a[j];sum+=num[cnt][i];}For(i,1,N)pos[a[i]=b[i]]=i;
	}
}
void print(){int siz=cnt;For(i,1,cnt)if(tot[i]==1)siz--;cout<<siz<<endl;For(i,1,cnt)if(tot[i]!=1){cout<<tot[i]<<' ';For(j,1,tot[i])cout<<num[i][j]<<' ';cout<<endl;}}
int main(){cin>>N;For(i,1,N)cin>>a[i],pos[a[i]]=i;For(i,1,N-1)opt(i);if(a[1]==N){tot[++cnt]=N;For(i,1,N)num[cnt][i]=1;}print();return 0;}