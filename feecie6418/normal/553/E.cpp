#include<bits/stdc++.h>
using namespace std;
int tr[70005],n,m,t,X,dis[55][55],a[105],b[105],c[105];
double f[55][40005],p[105][20005],g[105][40005];
void GetTr(int l) {
	for(int i=0; i<l; i++)tr[i]=(tr[i>>1]>>1)|((i&1)?(l>>1):0);
}
typedef complex<double> comp;
comp ta[70005],wk[70005],tb[70005];
void FFT(comp a[],int n,int flag) {
	for(int i=0; i<n; i++)if(tr[i]<i)swap(a[i],a[tr[i]]);
	for(int i=1; i<n; i<<=1) {
		comp w=exp(comp(0,flag*acos(-1)/i));
		for(register int j=1; j<i; j++)wk[j]=wk[j-1]*w;
		for(register int j=0; j<n; j+=(i<<1)) {
			for(register int k=0; k<i; k++) {
				comp t=a[i+j+k]*wk[k];
				a[i+j+k]=a[j+k]-t,a[j+k]+=t;
			}
		}
	}
	if(flag==-1)for(int i=0; i<n; i++)a[i]/=n;
}
void Solve(int l,int r){
	if(l>=t)return ;
	if(l==r){
		for(int i=1;i<=m;i++)if(a[i]^n)f[a[i]][l]=min(f[a[i]][l],g[i][l]+c[i]);
		return ;
	}
	int mid=(l+r)/2;
	Solve(mid+1,r);
	int len=1;
	while(len<=(r-l-1)+(r-mid-1))len<<=1;
	GetTr(len);
	for(int i=1;i<=m;i++){
		if(a[i]==n)continue;
		for(int j=0;j<len;j++)ta[j]=tb[j]=0;
		for(int j=1;j<=r-l&&j<=t;j++)ta[r-l-j]=p[i][j];
		for(int j=mid+1;j<=r;j++)tb[j-mid-1]=f[b[i]][j];
		FFT(ta,len,1),FFT(tb,len,1);
		for(int j=0;j<len;j++)ta[j]*=tb[j];
		FFT(ta,len,-1);
		for(int j=l;j<=mid;j++)g[i][j]+=ta[r-l-mid-1+j].real();
	}
	Solve(l,mid);
}
int main(){
	cin>>n>>m>>t>>X,memset(f,127,sizeof(f)),memset(dis,0x3f,sizeof(dis)),wk[0]=1;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z,dis[x][y]=z,a[i]=x,b[i]=y,c[i]=z;
		for(int j=1;j<=t;j++)scanf("%d",&x),p[i][j]=x/1e5;
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int j=1;j<=n;j++)for(int i=t;i<2*t;i++)f[j][i]=dis[j][n]+X;
	for(int i=0;i<=t;i++)f[n][i]=0;
	Solve(0,2*t-1),printf("%.10lf\n",f[1][0]);
}//