#include<bits/stdc++.h>
using namespace std;
const int N=60;
int w[N][N],p[N][N],q[N*N],to[N],M[N+N],T;
int cmp(int a,int b) {
	return w[T][a]<w[T][b];
}
int main() {
	int T_T,n;
	scanf("%d",&T_T);
	while(T_T--) {
		memset(M,0,sizeof(M));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",w[i]+j);
		cout<<"B"<<endl;
		char s[3];
		scanf("%s",s+1);
		if(s[1]=='D')
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					w[i][j]*=-1;
		int x;
		scanf("%d",&x);
		if(x<=n)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					w[i][j]*=-1;
		for(int i=1;i<=n;i++) {
			to[i]=n;
			for(int j=1;j<=n;j++)
				p[i][j]=j;
			T=i;
			sort(p[i]+1,p[i]+n+1,cmp);
			// for(int j=1;j<=n;j++)
			// 	printf("%d ",w[T][p[i][j]]);
			// puts("");
		}
		int h=1,e=0;
		for(int i=1;i<=n;i++)
			q[++e]=i;
		while(h<=e) {
			int x=q[h++],y=p[x][to[x]];
			// cerr<<x<<' '<<y<<' '<<w[x][y]<<endl;
			if(!M[y+n]||w[M[y+n]][y]>w[x][y]) {
				// cerr<<M[y+n]<<endl;
				if(M[y+n]) {
					to[M[y+n]]--;
					q[++e]=M[y+n];
				}
				M[y+n]=x;
				M[x]=y+n;
			} else {
				to[x]--;
				q[++e]=x;
			}
		}
		// for(int i=1;i<=n;i++)
		// 	cerr<<":"<<M[i]<<endl;
		for(int i=1;i<=n;i++) {
			cout<<M[x]<<endl;
			scanf("%d",&x);
			if(x==-1)break;
		}
	}
	return 0;
	// w(a,b)<w(b,c)
	//-w(c,b)>-w(c,d)
}