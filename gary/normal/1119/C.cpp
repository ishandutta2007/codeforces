#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;map<int,int> m1;
	map<int,int> m2;
	int a[501][501],b[501][501];
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) {
	scanf("%d",&b[i][j]);
	if(a[i][j]==b[i][j]){
		}
		else{
			m1[i]++;
			m2[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(m1[i]%2==1) {
			cout<<"No";
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		if(m2[i]%2==1) {
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}