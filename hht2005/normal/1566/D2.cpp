#include<bits/stdc++.h>
using namespace std;
const int N=310;
int a[N][N],n,m,T;
struct node {
	int a,id;
	operator<(const node &A) {
		return a==A.a?id<A.id:a<A.a;
	}
}p[N*N];
int main() {
	scanf("%d",&T);
	while(T--) {
		int c=0,ans=0;
		scanf("%d%d",&n,&m);//kjfhgjklhgvbjkl
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) {
				scanf("%d",&p[++c].a);
				p[c].id=c;
			}
		sort(p+1,p+c+1);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++)a[i][j]=(i-1)*m+j;
			for(int l=1,r=1;l<=m;l=++r) {
				while(r<m&&p[a[i][r]].a==p[a[i][r+1]].a)r++;
				reverse(a[i]+l,a[i]+r+1);
			}
			for(int j=2;j<=m;j++)
				for(int k=1;k<j;k++)
					ans+=p[a[i][k]].id<p[a[i][j]].id;
		}
		printf("%d\n",ans);
	}
	return 0;
}