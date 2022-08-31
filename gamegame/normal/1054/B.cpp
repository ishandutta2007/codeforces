#include<iostream>
using namespace std;
int n;
int num=-1;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int a;
		cin >> a;
		if(a>num+1){
			cout << i << endl;
			return 0;
		}
		if(a==num+1) num=a;
	}
	cout << -1 << endl;
}