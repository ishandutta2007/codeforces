#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[55][55];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'){
				int k=i;
				while(k<n&&a[k+1][j]=='.'){
					swap(a[k][j],a[k+1][j]);
					k++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]+1<<'\n';
	}
	puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}