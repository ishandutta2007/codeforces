#include<iostream>
using namespace std;
int n;
int a[101];
int k=0;
int sum=0;
bool check(){
	if(sum<k*n-sum) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		k=max(k,a[i]);
		sum+=a[i];
	}
	while(!check()) k++;
	cout << k << endl;
}