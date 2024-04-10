#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
 
#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
 
 
const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
 
using namespace std;
 


int n;
ll ans = INFll;
pll b[10004];

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".out");
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> b[i].second >> b[i].first;
	}
	sort (b, b + n);
	reverse(b, b + n);
	for (int i = 0; i < n; i++){
		ll h = max(b[i].first, b[i].second), w = min(b[i].first, b[i].second);
		bool flag = true;
		for (int j = 0; j < n; j++){
			if (j != i){
				if (max(b[j].first, b[j].second) <= h){
					w += min(b[j].first, b[j].second);
				} else if (min(b[j].first, b[j].second) <= h) {
					w += max(b[j].first, b[j].second);
				} else {
					flag = false;
				}
			}
		}
		if (flag){
			ans = min(ans, w * h);
		}
		h = min(b[i].first, b[i].second), w = max(b[i].first, b[i].second);
		flag = true;
			for (int j = 0; j < n; j++){
			if (j != i){
				if (max(b[j].first, b[j].second) <= h){
					w += min(b[j].first, b[j].second);
				} else if (min(b[j].first, b[j].second) <= h) {
					w += max(b[j].first, b[j].second);
				} else {
					flag = false;
				}
			}
		}
		if (flag){
			ans = min(ans, w * h);
		}
	}
	cout << ans << '\n';
}