#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,a[100002],mx[22][100002],mn[22][100002],lg[100002],L[22][100002],R[22][100002],c1[100002],c2[100002],cl[100002],cr[100002],ans[100002];
inline void add1(re int x,re int y){for(;x<=n;x+=x&(-x))c1[x]=max(c1[x],y);}
inline void add2(re int x,re int y){for(;x<=n;x+=x&(-x))c2[x]=min(c2[x],y);}
inline int ask1(re int x){re int s=0;for(;x;x^=x&(-x))s=max(s,c1[x]);return s;}
inline int ask2(re int x){re int s=n;for(;x;x^=x&(-x))s=min(s,c2[x]);return s;}
vector<int>V[100002];
inline int ask1(re int l,re int r){
	re int tmp=lg[r-l+1];
	return min(mn[tmp][l],mn[tmp][r-(1<<tmp)+1]);
}
inline int ask2(re int l,re int r){
	re int tmp=lg[r-l+1];
	return max(mx[tmp][l],mx[tmp][r-(1<<tmp)+1]);
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)mx[0][i]=mn[0][i]=read();
	for(re int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(re int i=1;i<=18;++i)
		for(re int j=1;j+(1<<i)-1<=n;++j)
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]),
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
	for(re int i=1;i<n;++i)L[0][i]=ask1(i,i+1),R[0][i]=ask2(i,i+1);
	for(re int i=1;i<=18;++i){
		for(re int j=1;j<=n;++j)mn[0][j]=L[i-1][j],mx[0][j]=R[i-1][j];
		for(re int ii=1;ii<=18;++ii)
			for(re int j=1;j+(1<<ii)-1<=n;++j)
				mx[ii][j]=max(mx[ii-1][j],mx[ii-1][j+(1<<ii-1)]),
				mn[ii][j]=min(mn[ii-1][j],mn[ii-1][j+(1<<ii-1)]);
		for(re int j=1;j<n;++j)L[i][j]=ask1(L[i-1][j],R[i-1][j]-1),R[i][j]=ask2(L[i-1][j],R[i-1][j]-1);
	}
	for(re int i=1;i<=m;++i)cl[i]=read(),cr[i]=read(),V[cl[i]].push_back(i);
	for(re int i=18;~i;--i){
		memset(c1,0,sizeof(c1)),memset(c2,0x3f,sizeof(c2));
		for(re int j=n;j;--j){
			if(j^n)add1(j+1,R[i][j]),add2(j+1,L[i][j]);
			for(auto z:V[j]){
				if(cl[z]==1&&cr[z]==n)continue;
				re int l=ask2(cr[z]),r=ask1(cr[z]);
				if(l^1||r^n)cl[z]=l,cr[z]=r,ans[z]+=1<<i;
			}V[j].clear();
		}for(re int j=1;j<=m;++j)V[cl[j]].push_back(j);
	}
	for(re int i=1;i<=m;++i){
		if(cl[i]==1&&cr[i]==n)puts("0");
		else if(cl[i]==cr[i])puts("-1");
		else if(ans[i]<262143)printf("%d\n",ans[i]+1);
		else puts("-1");
	}
		
}