#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define f first
#define s second
#define INF 1000000007

using namespace std;

int n, m, k, a[200005], c[100005];
vector < vector <int> > mass; 

int main(){
	//ifstream in ("in.txt");
	cin >> n >> m >> k;
	mass.resize(m);
	for (int i = 0; i < 100005; i++) c[i] = -1;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mass[a[i] - 1].push_back(i - c[a[i] - 1] - 1);
		c[a[i] - 1] = i;	
	}
	ll ans = 0;
	for (int i = 0; i < m; i++){
		if (mass[i].size() == 0) continue;
		int p1 = 1, p2 = 1, sz = mass[i].size(), now = 1, s = 0;
		while(p2 != sz && p1 != sz){
			if (mass[i][p2] + s <= k){
				now++;
				s += mass[i][p2];
				p2++;
			} else{
				if (now > ans) ans = now;
				s -= mass[i][p1];
				p1++; now--;
			}
		}
		if (now > ans) ans = now;
	}
	cout << ans;
	return 0;
}