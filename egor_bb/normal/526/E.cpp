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
 

ll n, q, d[2000005], sum[2000005], used[2000005], nxt[2000005], tm = 1;


int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".out");
//	freopen(problem".in", "r", stdin);
	scanf ("%I64d%I64d", &n, &q);
//	cin >> n >> q;
	for (int i =0 ; i < n; i++){
		scanf("%I64d", &d[i]);
//		cin >> d[i];
		d[i + n] = d[i];
		sum[i + 1] = sum[i] + d[i];
	}
	for (int i = n + 1; i <= 2 * n; i++){
		sum[i] = sum[i - 1] + d[i - 1];
	}
	for (int i =0 ;i < q ;i++){
		ll x = 0;
		int ans = INF;
//		scanf ("%I64d", &x);
		cin >> x;
		int p1 = 0, p2 = 0;
		while (p1 < n){
			while (sum[p2 + 1] - sum[p1] <= x) p2++;
			nxt[p1] = p2;
			nxt[p1 + n] = p2 + n;
			p1++;
		}
		tm++;
		for (int j = 0; j < n; j++){
			if (used[j] == tm) continue;
			p1 = p2 = j;
			int cnt = 0;
			while (p1 < n){
				bool flag = true;
				while (p2 - p1 < n){
					if (used[p2] == tm){
						flag = false;
						break;
					}
					used[p2] = tm;
					p2 = nxt[p2];
					cnt++;
				}
				if (!flag) break;
				ans = min(ans, cnt);
				cnt--;
				p1 = nxt[p1];
			}
		}
	//	printf("%I64d\n", &ans);
		cout << ans << '\n';
	}
}