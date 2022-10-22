#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int T,N,M,a[MAXN],sum1[MAXN],sum2[MAXN],val[MAXN],*sum3[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
void add(int x,int l,int r){if(x>N)return;sum3[x][l]++;if(r<M)sum3[x][r+1]--;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N*M)a[i]=getc();For(i,1,N)sum3[i]=val+(i-1)*M;For(i,1,M)vis[i]=0;For(i,1,N*M)sum1[i]=sum2[i]=val[i]=0;int pre=-1e7;
		For(i,1,N*M)if(a[i])
		{
			if(!vis[(i-1)%M+1])vis[(i-1)%M+1]=1,sum1[i]++;
			if(i-pre>=M)sum2[i]++;
			else
			{
				int l=i+M-(i-pre),r=min(N*M,i+M-1);if(l>r){pre=i;continue;}
				if((l-1)/M==(r-1)/M)add((l-1)/M+1,(l-1)%M+1,(r-1)%M+1);
				else add((l-1)/M+1,(l-1)%M+1,M),add((l-1)/M+2,1,(r-1)%M+1);
			}
			pre=i;
		}
		For(i,1,N*M)sum1[i]+=sum1[i-1],sum2[i]+=sum2[i-1];For(i,1,N)For(j,2,M)sum3[i][j]+=sum3[i][j-1];For(i,2,N)For(j,1,M)sum3[i][j]+=sum3[i-1][j];
		For(i,1,N*M)cout<<sum1[i]+sum2[i]+val[i]<<" \n"[i==N*M];
	}
}