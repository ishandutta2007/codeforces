#include<bits/stdc++.h>
using namespace std;
multiset<int, greater<int> > s;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n --){
		int d;
		cin >> d;
		s.insert(d);
	}
	int k = *s.begin();
	cout << k << " ";
	for(int i = 1; i <= k; i += 1) if(k % i == 0) s.erase(s.find(i));
	cout << *s.begin();
}