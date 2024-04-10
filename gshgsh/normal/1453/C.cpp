#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define INF 0x3fffffff
#define MAXN 2001
int T,N,a[MAXN][MAXN],cnt1[MAXN][10],mn1[MAXN][10],mn2[MAXN][10],mx1[MAXN][10],mx2[MAXN][10],cnt2[MAXN][10],ans[10];
int get(){char c=getchar();while(c<'0'||c>'9')c=getchar();return c-'0';}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)For(j,0,9)mx1[i][j]=mx2[i][j]=cnt1[i][j]=cnt2[i][j]=0,mn1[i][j]=mn2[i][j]=INF;For(i,0,9)ans[i]=0;
		For(i,1,N)For(j,1,N)a[i][j]=get(),cnt1[i][a[i][j]]++,cnt2[j][a[i][j]]++,mn1[i][a[i][j]]=min(mn1[i][a[i][j]],j),mx1[i][a[i][j]]=max(mx1[i][a[i][j]],j),mn2[j][a[i][j]]=min(mn2[j][a[i][j]],i),mx2[j][a[i][j]]=max(mx2[j][a[i][j]],i);
		For(k,0,9)For(i,1,N)For(j,1,N){if(cnt1[i][k]>=2&&cnt1[j][k]>=1)ans[k]=max(ans[k],abs(i-j)*max(N-mn1[i][k],mx1[i][k]-1));if(cnt1[i][k]>=2)ans[k]=max(ans[k],max(N-i,i-1)*(mx1[i][k]-mn1[i][k]));if(cnt1[i][k]>=1&&cnt1[j][k]>=1)ans[k]=max(ans[k],abs(j-i)*max(max(N-mn1[i][k],mx1[i][k]-1),max(N-mn1[j][k],mx1[j][k]-1)));}
		For(k,0,9)For(i,1,N)For(j,1,N){if(cnt2[i][k]>=2&&cnt2[j][k]>=1)ans[k]=max(ans[k],abs(i-j)*max(N-mn2[i][k],mx2[i][k]-1));if(cnt2[i][k]>=2)ans[k]=max(ans[k],max(N-i,i-1)*(mx2[i][k]-mn2[i][k]));if(cnt2[i][k]>=1&&cnt2[j][k]>=1)ans[k]=max(ans[k],abs(j-i)*max(max(N-mn2[i][k],mx2[i][k]-1),max(N-mn2[j][k],mx2[j][k]-1)));}
		For(i,0,9)cout<<ans[i]<<' ';cout<<endl;
	}
	return 0;
}