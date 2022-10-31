#pragma comment (linker, "/STACK:100000000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e17 + 7)
#define sort stable_sort

using namespace std;



ll t1, t2, x1, x2, t0;

/*ll gsum(ll a, ll b){
	return (sum[b] - sum[a - 1]);
}*/

ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}

bool check (ll c){
	
	return true;
	return false;
}

int main(){
//	ifstream cin ("in.txt");
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if (t1 == t2){
		cout << x1 << " " << x2;
		return 0;
	}
	double ans = 1000000000;
	ll x, y, bflow = 0;
	for (int i = 0; i <= x1; i++){
		if (!i){
			ans = t2;
			bflow = x2;
			x = i;
			y = x2;
		} else {
			ll lft = -1, rgt= x2, flow = 0;
			double best = 1000000000;
			while (rgt - lft > 1){
				ll m = (rgt + lft) / 2;
				double t = (t1 * i + t2 * m) * 1. / (i + m); 
					if (t - t0 >= 0 && t < best){
					best = t;
					flow = i + m;
					rgt = m;
				} else if (t >= 0 && t == best){
					flow = max(flow, i + m);
					lft = m;
				} else lft = m;
			}

			if ((t1 * i + t2 * rgt) * 1. / (i + rgt) >= t0){
				if (ans >  (t1 * i + t2 * rgt) * 1. / (i + rgt)){
					ans = (t1 * i + t2 * rgt) * 1. / (i + rgt);
					x = i;
					y = rgt;
					bflow = i + rgt;
				} else if (ans ==  (t1 * i + t2 * rgt) * 1. / (i + rgt)){
				//	cout << bflow << " " << i + rgt << '\n';
					if (bflow < i + rgt){

						bflow = i + rgt;
						x = i;
						y = rgt;
					}
				}
			}
		}
	}
	cout << x << " " << y;
	return 0;
}