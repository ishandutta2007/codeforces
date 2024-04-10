#include<iostream>
using namespace std;
bool a[1001];
int main(){
	int n,cur;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> cur;
		a[cur]=true;
	}
	for(int i=1; i<=998 ;i++){
		if(a[i] && a[i+1] && a[i+2]){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}