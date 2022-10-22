#include<bits/stdc++.h>
using namespace std;
int n,k,x;
long long a[205],f[205][205];
int main(){
	cin>>n>>k>>x;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n/k>x) {
		cout<<-1<<endl;return 0;
	}
	for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    f[i][j]=-1e18;
    f[0][0]=0;
	for(int j=1;j<=n;j++){//j 
		for(int i=1;i<=min(x,j);i++){//i 
			for(int v=max(0,j-k);v<j;v++){
				f[j][i]=max(f[v][i-1]+a[j],f[j][i]);
			}
			
		}
	}
	long long ans=0;
	for(int i=n-k+1;i<=n;i++) if(f[i][x]>ans) ans=f[i][x]; 
	cout<<ans<<endl;
	return 0;
}