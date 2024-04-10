#include<bits/stdc++.h>
using namespace std;
void no(){cout << -1; exit(0);}
constexpr int maxn = 300000;
int q[maxn];
set<int> s;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	s.insert(0);
	for(int i = 2; i <= n; i += 1){
		cin >> q[i];
		s.insert(q[i] += q[i - 1]);
	}
	if(s.size() < n) no();
	for(int i = 1; i <= n; i += 1){
		q[i] += (1 - *s.begin());
		if(q[i] < 1 or q[i] > n) no();
	}
	for(int i = 1; i <= n; i += 1) cout << q[i] << " ";
}