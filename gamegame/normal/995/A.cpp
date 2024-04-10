#include<iostream>
#include<vector>
using namespace std;
int n,k;
int a[5][51];
int nx[5][51],ny[5][51];
int f[5]={0,0,1,4,0};
vector<pair<int,pair<int,int> > >v;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=4 ;i++){
		for(int j=1; j<=n ;j++) cin >> a[i][j];
	}
	for(int i=1; i<n ;i++){
		nx[2][i+1]=2,ny[2][i+1]=i;
		nx[3][i]=3,ny[3][i]=i+1;
	}
	nx[2][1]=3,ny[2][1]=1;
	nx[3][n]=2,ny[3][n]=n;
	bool ok=false;
	for(int i=2; i<=3 ;i++){
		for(int j=1; j<=n ;j++){
			if(a[i][j]==0){
				ok=true;
				continue;
			}
			if(a[i][j]==a[f[i]][j]){
				ok=true;
				v.push_back({a[i][j],{f[i],j}});
				a[i][j]=0;
			}
		}
	}
	if(!ok){
		cout << -1 << endl;
		return 0;
	}
	for(int i=1; i<=2*n+50 ;i++){
		for(int j=1; j<=n ;j++){
			if(a[2][j]==0) continue;
			if(a[2][j]==a[1][j]){
				v.push_back({a[2][j],{1,j}});
				a[2][j]=0;
				continue;
			}
			if(a[nx[2][j]][ny[2][j]]==0){
				v.push_back({a[2][j],{nx[2][j],ny[2][j]}});
				a[nx[2][j]][ny[2][j]]=a[2][j];
				a[2][j]=0;
			}
		}
		for(int j=n; j>=1 ;j--){
			if(a[3][j]==0) continue;
			if(a[3][j]==a[4][j]){
				v.push_back({a[3][j],{4,j}});
				a[3][j]=0;
				continue;
			}
			if(a[nx[3][j]][ny[3][j]]==0){
				v.push_back({a[3][j],{nx[3][j],ny[3][j]}});
				a[nx[3][j]][ny[3][j]]=a[3][j];
				a[3][j]=0;
			}
		}
	}
	cout << v.size() << endl;
	for(int i=0; i<v.size() ;i++){
		cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << endl;
	}
}