#include <cstdio>
#include <algorithm>
using namespace std;
#define s(dn) scanf("%d",&n);
int x[51][51]={};
int c[2501][2];
int d[2501][4];
int y[51]={};
int n;
int ans=0,sum=0;
int main(){
	s(dn);
	for(int i=1;i<=n;i++){
		scanf("%d",&y[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=y[i];j++){
		scanf("%d",&x[i][j]);
		c[x[i][j]][0]=i;
		c[x[i][j]][1]=j;
	}
	}
	for(int i=1;i<=n;i++){
		ans+=y[i-1];
		for(int j=1;j<=y[i];j++){
			if(x[i][j]==ans+j){
				continue;
			}else{
				d[sum][0]=i;
				d[sum][1]=j;
				d[sum][2]=c[ans+j][0];
				d[sum][3]=c[ans+j][1];
				int s=x[i][j];
				x[i][j]=ans+j;
				x[c[ans+j][0]][c[ans+j][1]]=s;
				swap(c[s][0],c[ans+j][0]);
				swap(c[s][1],c[ans+j][1]);
				sum++;
			}
		}
	}
	printf("%d\n",sum);
	for(int i=0;i<sum;i++){
		printf("%d %d %d %d\n",d[i][0],d[i][1],d[i][2],d[i][3]);
	}
	scanf("%d",&sum);
	return 0;
}