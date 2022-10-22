//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int N=105;
int a[N][N],sum[N],id[N],st[N],n,m,pos,pp,mn;
int calc(int p,bool fl){
	pp=p;
	sort(id+1,id+1+m,[](const int &x,const int &y){return a[x][n]-a[x][pp]>a[y][n]-a[y][pp];});
	R int s=sum[n]-sum[p],cnt=0;
	for(R int i=1;s>0&&i<=m;++i){
		s-=a[id[i]][n]-a[id[i]][p];
		++cnt;
		if(fl)printf("%d ",id[i]);
	}
	return cnt;
}
int main(){
	scanf("%d%d",&n,&m);
	fp(i,1,m){
		fp(j,1,n)scanf("%d",&a[i][j]),sum[j]+=a[i][j];
		id[i]=i;
	}
	mn=m,pos=1;
	fp(i,1,n-1)if(cmin(mn,calc(i,0)))pos=i;
	printf("%d\n",mn);
	calc(pos,1);
	return 0;
}