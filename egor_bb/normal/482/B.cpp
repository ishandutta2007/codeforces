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

#define ll int
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




ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}

struct Vert{
	ll sum, push;
	Vert(){ sum = push = 0;};
};


ll n, m, q;
vector < vector <ll> > mass, sum;
vector <vector < Vert > > Tree;





void add(ll num, ll l, ll r, ll a, ll b, ll v){
	if (l > b || r < a) return;
	if (l >= a && r <= b) {
		Tree[num][v].push = 1;
		Tree[num][v].sum = r - l + 1;
	}
	if (Tree[num][v].push) return;
	add(num, l, (l + r) / 2, a, b, 2 * v);
	add(num, (l + r) / 2 + 1, r, a, b, 2 * v + 1);
	Tree[num][v].sum = Tree[num][2 * v].sum + Tree[num][2 * v + 1].sum;
}

void push (ll num, ll v, ll type, ll l, ll r){
	if (v >= 2 * m) return;
	if (type){
		Tree[num][v].push = 1;
		Tree[num][v].sum = r - l + 1;
	}
	push(num, 2 * v, Tree[num][v].push, l, (l + r) / 2);
	push(num, 2 * v + 1, Tree[num][v].push, (l + r) / 2 + 1, r);
	if (2 * v < 2 * m) Tree[num][v].sum = Tree[num][2 * v].sum + Tree[num][2 * v + 1].sum;
}


int main(){
//	ifstream cin ("in.txt");
	cin >> n >> q;

	ll nn = n;
	m = 1;
	while (nn){
		nn >>= 1;
		m <<= 1;
	}
	Tree.resize(30, vector <Vert> (2 * m));
	mass.resize(q + 5, vector <ll> (30, 0));

	for (ll i = 0; i < q; i++){
		cin >> mass[i][0] >> mass[i][1] >> mass[i][2];
		for (ll j = 0; j < 30; j++){
			if ((1ll << j) & mass[i][2]){
				add(j, 0, m - 1,  mass[i][0] - 1, mass[i][1] - 1, 1);
			}
		}
	}

	for (ll j = 0; j < 30; j++){
		push(j, 1, 0, 0, m - 1);
	}

	sum.resize(30, vector <ll> (n + 5, 0));
	for (int j = 0; j < 30; j++){
		for (int i = 1; i <= n; i++){
			sum[j][i] = sum[j][i - 1] + Tree[j][m + i - 1].sum;
		}
	}
	
	for (ll i = 0; i < q; i++){
		for (ll j = 0; j < 30; j++){
			if ((1ll << j) & mass[i][2]){
				if (sum[j][mass[i][1]] - sum[j][mass[i][0] - 1] != mass[i][1] - mass[i][0] + 1){
					cout << "NO";
					return 0;
				}
			} else {
				if (sum[j][mass[i][1]] - sum[j][mass[i][0] - 1] == mass[i][1] - mass[i][0] + 1){
					cout << "NO";
					return 0;
				}
			}
		}
	}


	cout << "YES\n";
	for (ll i = 0; i < n; i++){
		ll num = 0;
		for (ll j = 0; j < 30; j++){
			if (Tree[j][m + i].sum == 1) num += 1ll << j; 
		}
		cout << num << " ";
	}
	return 0;
}