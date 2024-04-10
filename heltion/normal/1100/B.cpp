#include<bits/stdc++.h>
using namespace std;
#define maxn 120
int a[maxn];
multiset<int> p;
set<int> s;
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i += 1){
		int a;
		cin >> a;
		if(s.count(a)) p.insert(a);
		else s.insert(a);
		if(s.size() == n){
			cout << 1;
			s.clear();
			for(int i = 1; i <= n; i += 1) {
				auto it = p.find(i);
				if(it != p.end()){
					s.insert(i);
					p.erase(it);
				}
			}
		}
		else cout << 0;
	}
}