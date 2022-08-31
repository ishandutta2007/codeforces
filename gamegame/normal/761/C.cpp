#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
char a[51][51];
int mini[51][3];
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=3 ;j++) mini[i][j]=1e7;
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
			if(a[i][j]>=48 && a[i][j]<=57) mini[i][1]=min(mini[i][1],min(j-1,m-j+1));
			else if(a[i][j]>='a' && a[i][j]<='z') mini[i][2]=min(mini[i][2],min(j-1,m-j+1));
			else mini[i][3]=min(mini[i][3],min(j-1,m-j+1));
		}
	}
	int ans=2e9;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			for(int k=1; k<=n ;k++){
				if(i==j || j==k || i==k) continue;
				ans=min(ans,mini[i][1]+mini[j][2]+mini[k][3]);
			}
		}
	}
	cout << ans << endl;
}