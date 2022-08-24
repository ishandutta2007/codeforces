#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	int bs=sqrt(n);
	for(int i=bs; i<n+bs ;i+=bs){
		for(int j=min(i,n); j>=(i-bs+1) ;j--){
			cout << j << ' ';
		}
	}
}