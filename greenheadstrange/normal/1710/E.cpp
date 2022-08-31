//http://zhengruioi.com/submission/344507
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
int a[300010],b[300010];
int Sx,Sy;
int ta[300010],tb[300010];
int T;
bool check(int mid){
	int a1=0,a2=0;
	int j=1;
	int nw=0,tmp=0;
	for(int i=n;i>=1;--i){
		while(nw<m&&a[i]+b[nw+1]<=mid) ++nw;
		tmp+=nw;ta[i]=nw;
	}
	ta[0]=m;
	// for(int i=1;i<=n;++i) printf("%d ",ta[i]);printf("\n");
	nw=0;int s=0;
	for(int i=m;i>=1;--i){
		while(nw<n&&a[nw+1]+b[i]<=mid) ++nw;
		tb[i]=nw;s+=nw;
	}
	tmp=1ll*n*m-tmp;
	// printf("s:%d\n",s);
	// printf("%d\n",tmp);
	a1=tmp,a2=tmp-1;
	nw=tmp;j=1;
	for(int i=1;i<=n;++i){
		nw+=min(j-1,ta[i])-min(m-j+1,m-ta[i]);
		// printf("i:%d,nw:%d\n",i,nw);
		// printf("j:%d\n",j);
		// printf("%d %d\n",min(j-1,ta[i]),min(m-j+1,m-ta[i]));
		while(j<=m&&min(n-i,n-tb[j])<=min(tb[j],i)){
			nw+=min(tb[j],i)-min(n-i,n-tb[j]);
			// printf("mpve:%d %d\n",min(i,tb[j]),min(n-i,n-tb[j]));
			++j;
		}
		a1=max(a1,nw);
	}
	nw=tmp-1;j=1;
	// printf("%d %d\n",tb[Sy]<Sx,t.a[Sx]<Sy);
	for(int i=1;i<=n;++i){
		nw+=min(j-1,ta[i])-min(m-j+1,m-ta[i])+(i==Sx&&j<=Sy);
		// printf("nw:%d\n",nw);
		// printf("j:%d ",j);
		while(j<=m&&min(n-i,n-tb[j])<=(j==Sy&&i<Sx)+min(tb[j],i)){
			nw+=(j==Sy&&i<Sx)+min(tb[j],i)-min(n-i,n-tb[j]);++j;
		}
		// printf("%d\n",j);
		a2=max(a2,nw);
		// printf("%d\n",nw);
	}
	// printf("mid:%d,%d %d\n",mid,a1,a2);
	return a1==a2;
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) b[i]=read();
	Sx=a[1],Sy=b[1];
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	int l=a[1]+b[1],r=Sx+Sy,res=r;--r;
	for(int i=1;i<=n;++i) if(a[i]==Sx){
		Sx=i;break ;
	}
	for(int i=1;i<=m;++i){
		if(b[i]==Sy){
			Sy=i;break ;
		}
	}
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",res);
}