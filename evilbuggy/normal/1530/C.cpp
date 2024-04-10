#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		deque<int> a(n);
		deque<int> b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int i = 1; i < n; i++){
			a[i] += a[i - 1];
			b[i] += b[i - 1];
		}
		int answer = 0;
		while(true){
			int k = (n/4);
			int vala = a[n - 1];
			int valb = b[n - 1];
			if(k != 0)vala -= a[k - 1];
			if(k != 0)valb -= b[k - 1];
			if(vala >= valb)break;
			a.push_back(a.back() + 100);
			b.push_front(0);
			answer++; n++;
		}
		cout << answer << '\n';
	}

	return 0;
}