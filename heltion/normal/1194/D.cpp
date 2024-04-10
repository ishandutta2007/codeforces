//Author: Heltion
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int SG[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(12);
	/*
	int k;
	cin >> k;
	for(int i = 1; i < maxn; i += 1){
		set<int> s;
		if(i >= 1) s.insert(SG[i - 1]);
		if(i >= 2) s.insert(SG[i - 2]);
		if(i >= k) s.insert(SG[i - k]);
		while(s.count(SG[i])) SG[i] += 1;
		cout << SG[i] << " ";
	}
	*/
	int T;
	for(cin >> T; T; T -= 1){
		int n, k;
		cin >> n >> k;
		if(k % 3) cout << (n % 3 ? "Alice\n" : "Bob\n");
		else cout << (n % (k + 1) % 3 or n % (k + 1) == k ? "Alice\n" : "Bob\n");
	}
	return 0;
}