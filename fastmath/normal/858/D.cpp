#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;
const int LEN = 9;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;
const string INF = "000000000000";
const int ALPH = 10;

string ans;
int it = 0;

struct Node{
	bool good;
	int last;
	Node* go[ALPH];
};

Node *init(){
	Node *res = new Node();
	res->good = true;
	res->last = -1;
	for (int i = 0; i < ALPH; ++i){
		res->go[i] = NULL;
	}

	return res;
}

Node *add(Node *t, string s, int i, string pref){
	t->last = it;
	if (i == s.size()) return t;

	int ind = s[i] - '0';

	if (!t->go[ind]){
		t->go[ind] = init();
	}
	else if (t->go[ind]->last != -1 && t->go[ind]->last != it){
		t->go[ind]->good = false;
	}

	t->go[ind] = add(t->go[ind], s, i + 1, pref + s[i]);
	return t;
}

void get(Node *t, string s, int i, string pref){
	if (pref.size() && pref.size() < ans.size() && t->good){
		ans = pref;
	}

	if (i == s.size()) return;
	get(t->go[s[i] - '0'], s, i + 1, pref + s[i]);
}

string slice(string s, int l, int r){
	string res = "";
	for (int i = l; i <= r; ++i) res += s[i];
	return res;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <string> a(n);
	Node *root = init();
	for (; it < n; ++it){
		cin >> a[it];
		for (int l = 0; l < LEN; ++l){
			root = add(root, slice(a[it], l, LEN - 1), 0, "");
		}
	}

	it = 0;
	for (; it < n; ++it){
		ans = INF;
		for (int l = 0; l < LEN; ++l){
			get(root, slice(a[it], l, LEN - 1), 0, "");
		}
		cout << ans << '\n';
	}
	return 0;
}