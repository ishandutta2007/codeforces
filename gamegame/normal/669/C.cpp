#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,m,q,t;
	cin >> n >> m >> q;
	int a[n+1][m+1];
	pair<int,int>b[n+1][m+1],c[n+1][m+1];
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			a[i][j]=0;
			b[i][j]=make_pair(i,j);
		}
	}
	int d[q+1][4];
	for(int i=1; i<=q ;i++){
		cin >> d[i][0];
		if(d[i][0]==1){
			cin >> d[i][1];
			pair<int,int> tem;
			for(int j=1; j<=m-1 ;j++){
				tem=b[d[i][1]][j];
				b[d[i][1]][j]=b[d[i][1]][j+1];
				b[d[i][1]][j+1]=tem;
			}
		}
		else if(d[i][0]==2){
			cin >> d[i][1];
			pair<int,int>tem;
			for(int j=1; j<=n-1 ;j++){
				tem=b[j][d[i][1]];
				b[j][d[i][1]]=b[j+1][d[i][1]];
				b[j+1][d[i][1]]=tem;
			}
		}
		else{
			cin >> d[i][1] >> d[i][2] >> d[i][3];
			a[b[d[i][1]][d[i][2]].first][b[d[i][1]][d[i][2]].second]=d[i][3];
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}