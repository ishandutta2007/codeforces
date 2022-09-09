#include<bits/stdc++.h>
using namespace std;
using LL = long long;
map<int, int> mp;
int main(){
	int n;
	cin >> n;
	while(n --){
		int a;
		cin >> a;
		mp[a] += 1;
	}
	for(auto p : mp) if(p.second & 1){
		cout << "Conan";
		return 0;
	}
	cout << "Agasa";
}