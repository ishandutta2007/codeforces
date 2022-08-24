#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200001];
multiset<int>s;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++){
		int x;cin >> x;s.insert(x);
	}
	for(int i=1; i<=n ;i++){
		auto it=s.lower_bound(n-a[i]);
		if(it==s.end()) it=s.begin();
		cout << (a[i]+*it)%n << ' ';
		s.erase(it);
	}
}