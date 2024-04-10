#include <bits/stdc++.h>
	 
#define x first
#define y second
#define mp make_pair
#define pub push_back
#define all(a) a.begin(), a.end()
#define ll long long
#define db double
	 
using namespace std;

int n;
set<int> se;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	multiset<int> se;
	se.insert(0);
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (se.find(x) != se.end()){
			se.erase(se.find(x));
		} 
		se.insert(i + 1);
	}
	cout << se.size();
}