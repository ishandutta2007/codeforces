#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int sum=0;
	int cur=0;
	int tem;
	for(int i=0; i<n ;i++){
		cin >> tem;
		cur=(cur|tem);
	}
	sum=cur;
	cur=0;
	for(int i=0; i<n ;i++){
		cin >> tem;
		cur=(cur|tem);
	}
	sum+=cur;
	cout << sum << endl;
}