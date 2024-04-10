#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+100;
int a[N],b[N][2];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=1;i<=m;i++){
			int x;scanf("%d",&x);
			b[i][0]=b[i][1]=-1;
			for(int j=1;j<=x;j++){
				int t;scanf("%d",&t);
				if(x==1) a[t]++;
				if(j<=2) b[i][j-1]=t;
			}
		}
		bool pd=true;
		for(int i=1;i<=n;i++)
			if(a[i]>(m+1)/2) {pd=false;break;}
		if(!pd) printf("NO\n");
		else{
			printf("YES\n");
			//for(int i=1;i<=n;i++) a[i]=0;
			for(int i=1;i<=m;i++){
				if(b[i][1]==-1) printf("%d ",b[i][0]);
				else{
					if(a[b[i][0]]<(m+1)/2) a[b[i][0]]++,printf("%d ",b[i][0]);
					else printf("%d ",b[i][1]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}