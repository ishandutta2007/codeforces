//Author: Heltion
//Date: 10-16-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
int a[maxn], b[maxn], pa[maxn], p[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		pa[a[i]] = i;
	}
	for(int i = 1; i <= n; i += 1) cin >> b[i];
	for(int i = 1; i <= n; i += 1) p[i] = pa[b[i]];
	set<int> s;
	for(int i = 1; i <= n; i += 1) s.insert(i);
	int m = 0;
	for(int i = 1; i <= n; i += 1){
		if(*s.begin() == p[i]) m += 1;
		s.erase(p[i]);
	}
	cout << n - m;
	return 0;
}