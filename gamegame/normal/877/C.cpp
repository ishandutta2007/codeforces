#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin >> n;
	vector<int>v;
	for(int i=n-1; i>=1 ;i-=2){
		v.push_back(i);
	}
	for(int i=n; i>=1 ;i-=2){
		v.push_back(i);
	}
	for(int i=n-1; i>=1 ;i-=2){
		v.push_back(i);
	}
	cout << v.size() << endl;
	for(auto c:v) cout << c << ' ';
	cout << endl;
}