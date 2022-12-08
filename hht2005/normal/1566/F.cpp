#include<bits/stdc++.h>
using namespace std;
#define l fisrt
#define r second
const int N=6e5+10;
int a[N],c[N],sum[N];
long long Min[N][2];
vector<long long>f[N];
struct node {
	int l,r;
	int operator<(const node &a)const {
		return r==a.r?l>a.l:r<a.r;
	}
}L[N];
int main() {
	int T,n,m;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		int M=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			c[++M]=a[i];
		}
		for(int i=1;i<=m;i++) {
			scanf("%d%d",&L[i].l,&L[i].r);
			c[++M]=L[i].l,c[++M]=L[i].r;
		}
		sort(a+1,a+n+1);
		sort(c+1,c+M+1);
		for(int i=0;i<=M;i++)sum[i]=0,f[i].clear();
		M=unique(c+1,c+M+1)-c-1;
		for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+M+1,a[i])-c;
		for(int i=1;i<=m;i++) {
			L[i].l=lower_bound(c+1,c+M+1,L[i].l)-c;
			L[i].r=lower_bound(c+1,c+M+1,L[i].r)-c;
		}
		for(int i=1;i<=n;i++)sum[a[i]]++;
		for(int i=1;i<=M;i++)sum[i]+=sum[i-1];
		sort(L+1,L+m+1);
		int top=0;
		for(int i=1;i<=m;i++) {
			if(sum[L[i].r]!=sum[L[i].l-1])continue;
			if(!top||L[i].l>L[top].l)L[++top]=L[i];
		}
		m=top;
		a[0]=0;
		a[n+1]=2e9;
		int x=0;
		f[0].push_back(0);
		while(x<m&&L[x+1].r<a[1])
			f[0].push_back(4e9),x++;
		for(int i=1,j=x;i<=n;i++) {
			int y=0;
			while(j<m&&L[j+1].r<a[i+1])j++,y++;
			for(int k=0;k<x;k++) {
				Min[k][0]=f[i-1][k]+c[a[i]]-c[L[j-y-x+k+1].r];
				Min[k][1]=f[i-1][k]+2*(c[a[i]]-c[L[j-y-x+k+1].r]);
			}
			Min[x][0]=Min[x][1]=f[i-1][x];
			for(int k=1;k<=x;k++)Min[k][0]=min(Min[k][0],Min[k-1][0]);
			for(int k=x-1;k>=0;k--)Min[k][1]=min(Min[k][1],Min[k+1][1]);
			for(int k=0,o=x-1;k<=y;k++) {
				int b=k?c[L[j-y+k].l]-c[a[i]]:0;
				while(o>=0&&c[a[i]]-c[L[j-y-x+o+1].r]<b)o--;
				long long t=o>=0?min(Min[o][0]+2*b,Min[o+1][1]+b):Min[o+1][1]+b;
				f[i].push_back(t);
			}
			x=y;
		}
		printf("%lld\n",f[n][x]);
	}
	return 0;
}