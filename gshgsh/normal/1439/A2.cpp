#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,M,a[MAXN][MAXN],ans,pos[MAXN*MAXN][3][2];
void opt(int x0,int y0,int x1,int y1,int x2,int y2){a[x0][y0]^=1,a[x1][y1]^=1,a[x2][y2]^=1;pos[++ans][0][0]=x0,pos[ans][0][1]=y0,pos[ans][1][0]=x1,pos[ans][1][1]=y1,pos[ans][2][0]=x2,pos[ans][2][1]=y2;}
void sol1(int p,int q){int cnt=0,x[4],y[4];For(i,p,p+1)For(j,q,q+1)if(a[i][j])x[++cnt]=i,y[cnt]=j;opt(x[1],y[1],x[2],y[2],x[3],y[3]);}
void sol2(int p,int q){int cnt1=0,cnt2=0,x[4],y[4];For(i,p,p+1)For(j,q,q+1){if(a[i][j]&&!cnt1)x[(++cnt1)+cnt2]=i,y[cnt1+cnt2]=j;if(!a[i][j]&&cnt2<2)x[cnt1+(++cnt2)]=i,y[cnt1+cnt2]=j;}opt(x[1],y[1],x[2],y[2],x[3],y[3]);sol1(p,q);}
void sol3(int p,int q){int cnt1=0,cnt2=0,x[4],y[4];For(i,p,p+1)For(j,q,q+1){if(a[i][j]&&!cnt1)x[(++cnt1)+cnt2]=i,y[cnt1+cnt2]=j;if(!a[i][j]&&cnt2<2)x[cnt1+(++cnt2)]=i,y[cnt1+cnt2]=j;}opt(x[1],y[1],x[2],y[2],x[3],y[3]);sol2(p,q);}
void sol4(int p,int q){opt(p,q,p,q+1,p+1,q);sol3(p,q);}
void sol(int x,int y){int cnt=0;For(i,x,x+1)For(j,y,y+1)cnt+=a[i][j];if(!cnt)return;if(cnt==3)return sol1(x,y);if(cnt==2)return sol2(x,y);if(cnt==1)return sol3(x,y);return sol4(x,y);}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;ans=0;For(i,1,N)For(j,1,M){char c;cin>>c;a[i][j]=c-'0';}if(N&1)For(i,1,M)if(a[N][i])opt(N,i,N-1,i,N-1,i!=1?i-1:i+1);if(M&1)For(i,1,N)if(a[i][M])opt(i,M,i,M-1,i!=1?i-1:i+1,M-1);
		for(int i=1;i<N;i+=2)for(int j=1;j<M;j+=2)sol(i,j);cout<<ans<<endl;For(i,1,ans){For(j,0,2)For(k,0,1)cout<<pos[i][j][k]<<' ';cout<<endl;}
	}
	return 0;
}