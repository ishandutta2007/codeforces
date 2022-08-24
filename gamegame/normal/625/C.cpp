#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	int a[n+1][n+1];
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=k-1 ;j++){
			a[i][j]=(i-1)*(k-1)+j;
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=k ; j<=n ;j++){
			a[i][j]=(i-1)*(n-k+1)+(k-1)*n+j-k+1;
		}
	}
	int sum=0;
	for(int i=1; i<=n ;i++){
		sum+=a[i][k];
	}
	cout << sum << endl;
	for(int i=1; i<=n ;i++){
		cout << a[i][1];
		for(int j=2; j<=n ;j++){
			cout << " " << a[i][j];
		}
		cout << endl;
	}
}