#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,K,w,a[505][505],b[505][505],f[13][505][505];
int p1=1000000;
char buf[1000005];
int gc(){
	//return getchar();
	if(p1>=1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x;
}
inline void upd(int &x,int y){
	x=min(x,y);
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	n=rd(),m=rd(),K=rd(),w=K/2;
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++)a[i][j]=rd();
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)b[i][j]=rd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int ans=1e9;
			for(int s=0;s<=10;s++)for(int k=max(i-w,1);k<=min(i+w,n);k++)for(int l=max(j-(w-abs(i-k)),1),P=min(j+(w-abs(i-k)),m);l<=P;l++)f[s][k][l]=0x3f3f3f3f;
			f[0][i][j]=0;
			for(int s=0;s<10;s++)
				for(int k=max(i-s,1);k<=min(i+s,n);k++)
					for(int l=max(j-(s-abs(i-k)),1),P=min(j+(s-abs(i-k)),m);l<=P;l++){
						if(k>1)upd(f[s+1][k-1][l],f[s][k][l]+b[k-1][l]);
						if(k<n)upd(f[s+1][k+1][l],f[s][k][l]+b[k][l]);
						if(l>1)upd(f[s+1][k][l-1],f[s][k][l]+a[k][l-1]);
						if(l<m)upd(f[s+1][k][l+1],f[s][k][l]+a[k][l]);
					}
			for(int k=max(i-w,1);k<=min(i+w,n);k++)for(int l=max(j-(w-abs(i-k)),1),P=min(j+(w-abs(i-k)),m);l<=P;l++)ans=min(ans,f[(K+1)/2][k][l]+f[K/2][k][l]);
			if(ans<1e9)cout<<ans<<' ';
			else printf("-1 ");
		}
		puts("");
	}
}