#include<bits/stdc++.h> 
using namespace std;
using LL = long long; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	set<int> s;
	int n;
	cin >> n;
	for(int i = 0, a; i < n; i += 1){
		cin >> a;
		s.insert(a);
	}
	s.erase(0);
	cout << s.size();
	return 0;
}