#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 240000;
int q[maxn], qh, qt;
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	set<int> s;
	for(int i = 0, id; i < n; i += 1){
		cin >> id;
		if(not s.count(id)){
			if(qt - qh == k){
				s.erase(q[qh]);
				qh += 1;
			}
			q[qt ++] = id;
			s.insert(id);
		}
	}
	cout << qt - qh << "\n";
	for(int i = qt - 1; i >= qh; i -= 1) cout << q[i] << " ";
}