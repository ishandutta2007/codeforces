#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int a[11][11],n,t,ans=0;
void pour(int i,int j,int amount){
	if(i==n){
		a[i][j]=min(1024,a[i][j]+amount);
	}
	else if(a[i][j]+amount<=1024){
		a[i][j]+=amount;
	}
	else{
		pour(i+1,j,(a[i][j]+amount-1024)/2);
		pour(i+1,j+1,(a[i][j]+amount-1024)/2);
		a[i][j]=1024;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> t;
	for(int i=1; i<=t ;i++){
		pour(1,1,1024);
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			if(a[i][j]==1024){
				ans++;
			}
		}
	}
	cout << ans << endl;
}