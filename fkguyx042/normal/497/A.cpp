
 #include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
char a[105][105];
bool flag[105][105];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	int ans=0;
	for(int j=1;j<=m;j++){
		bool ok=true;
		for(int i=1;i<=n;i++)
			for(int ii=i+1;ii<=n;ii++) if(!flag[i][ii])
				if(a[i][j]>a[ii][j]){
					ok=false;
					break;
				}
		if(!ok){ ans++; continue; }
		for(int i=1;i<=n;i++)
			for(int ii=i+1;ii<=n;ii++) if(!flag[i][ii])
				if(a[i][j]<a[ii][j])
					flag[i][ii]=true;
	}
	printf("%d\n",ans);
	scanf("\n");
}