#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,a[5005],b[5005][5005];
ll ans,sum;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=b[i][j-1]+(a[j]<i);
		}
	}
	ans=0;
	for(int x=1;x<=n;x++){
		sum=0;
		for(int y=x+2;y<=n;y++){
			sum-=(y-2-x)-(b[a[y]][y-2]-b[a[y]][x]);
			sum+=(b[a[y-1]][n]-b[a[y-1]][y]);
			if(a[x]<a[y])ans+=sum;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}