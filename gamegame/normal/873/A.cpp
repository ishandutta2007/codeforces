#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,x,k;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> x;
	int sum=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=n-k ;i++){
		sum+=a[i];
	}
	cout << sum+x*k << endl;
}