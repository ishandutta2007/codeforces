#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int main() {
	int t;
	scanf("%d",&t);
	int a[305][305];
	int val[305][305];
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		
		for(int i = 0;i<n;i++){
			for(int j =0;j<m;j++){
				scanf("%d",&a[i][j]);
				val[i][j]=0;
			}
		}
		int ok=1;
		for(int i = 0;i<n;i++){
			for(int j =0;j<m;j++){
				if(a[i][j]){
					val[i][j]=a[i][j];
					int cnt=0;
					for(int k = 0;k<4;k++){
						int x=i+X[k],y=j+Y[k];
						if(x>=0&&x<n&&y>=0&&y<m){
							val[x][y]=1;
							cnt++;
						}
						if(cnt==a[i][j])break;
					}
					if(cnt!=a[i][j]){
						ok=0;
					}
				}
			}
		}
		if(!ok)printf("NO\n");
		else{
			printf("YES\n");
			for(int i = 0;i<n;i++){
				for(int j=0;j<m;j++){
					if(!val[i][j])printf("0 ");
					else{
						int cnt=0;
						for(int k=0;k<4;k++){
							int x=i+X[k],y=j+Y[k];
							if(x>=0&&x<n&&y>=0&&y<m&&val[x][y]){
							//	val[i][j]=1;
								cnt++;
							}
						}
						printf("%d ",cnt);
					}
					
				}
				printf("\n");
			}

		}
	}
	return 0;
}