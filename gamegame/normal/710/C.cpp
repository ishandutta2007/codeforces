#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int m=n/2+1;
	int a[n+1][n+1];
	int k=1,l=2;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			if(abs(m-i)+abs(m-j)<m){
				cout << k << ' ';
				k+=2;
			}
			else{
				cout << l << ' ';
				l+=2;
			}
		}
		cout << endl;
	}
}