#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,a[1005]; 
double f[1005][1005],ans;
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(a[i]>a[j])f[i][j]=1;
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
		f[x][y]=f[y][x]=(f[x][y]+f[y][x])/2;
		for(int j=1;j<=n;j++)
			if(j!=x&&j!=y){
				f[x][j]=f[y][j]=(f[x][j]+f[y][j])/2;
				f[j][x]=f[j][y]=(f[j][x]+f[j][y])/2;
			}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans+=f[i][j];
	printf("%.10lf\n",ans);
}