#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000][1000],xx,yy;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)cin>>a[i][j],a[i][j]+=a[i-1][j];
	for (int i=1;i<=m;i++){
		int sum=0,kk=0;
		for (int j=k;j<=n;j++)
			if (a[j][i]-a[j-k][i]>sum)sum=a[j][i]-a[j-k][i],kk=a[j-k][i];
		xx+=sum;yy+=kk;
	}cout<<xx<<' '<<yy<<endl;
}