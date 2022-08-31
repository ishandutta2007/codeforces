#include<iostream>
using namespace std;
int main(){
	int x;
	cin >> x;
	long long int a[2001],b[2001];
	for(int i=0; i<=2000 ;i++){
		a[i]=0;
		b[i]=0;
	}
	int p,q;
	for(int i=0; i<x ;i++){
		cin >> p >> q;
		a[p+q]++;
		b[p-q+1000]++;
	}
	long long int ans=0;
	for(int i=0; i<=2000 ;i++){
		ans+=a[i]*(a[i]-1)/2;
		ans+=b[i]*(b[i]-1)/2;
	}
	cout << ans << endl;
}