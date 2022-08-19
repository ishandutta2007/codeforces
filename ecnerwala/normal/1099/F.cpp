#define NDEBUG
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 mt(1203023);
using rand_int = mt19937::result_type;
struct treap {
	rand_int pri = mt();
	rand_int rkey = mt();
	treap* ch[2] = {nullptr, nullptr};
	ll key;
	ll cnt;

	auto getkey() {
		return make_pair(key, rkey);
	}

	ll totcnt = 0;
	ll totsum = 0;

	void update() {
		totcnt = cnt + (ch[0] ? ch[0]->totcnt : 0) + (ch[1] ? ch[1]->totcnt : 0);
		totsum = cnt * key + (ch[0] ? ch[0]->totsum : 0) + (ch[1] ? ch[1]->totsum : 0);
	}
};
std::ostream& operator << (std::ostream& a, treap* t) {
	if (!t) return a;
	assert(t->totcnt == t->cnt + (t->ch[0] ? t->ch[0]->totcnt : 0) + (t->ch[1] ? t->ch[1]->totcnt : 0));
	assert(t->totsum == t->cnt * t->key + (t->ch[0] ? t->ch[0]->totsum : 0) + (t->ch[1] ? t->ch[1]->totsum : 0));
	a << t->ch[0];
	a << "(" << t->key << "*" << t->cnt << ")";
	a << t->ch[1];
	return a;
}

pair<treap*, treap*> split_val(pair<ll, rand_int> split_point, treap* a) {
	if (a == nullptr) {
		return {nullptr, nullptr};
	}
	// make a copy
	treap* na = new treap(*a);
	if (na->getkey() > split_point) {
		auto sp = split_val(split_point, a->ch[0]);
		na->ch[0] = sp.second;
		na->update();
		return {sp.first, na};
	} else {
		auto sp = split_val(split_point, a->ch[1]);
		na->ch[1] = sp.first;
		na->update();
		return {na, sp.second};
	}
}

treap* insert(treap* curTree, treap* newNode) {
	assert(newNode);
	if (curTree != nullptr && curTree->pri < newNode->pri) {
		treap* newTree = new treap(*curTree);
		if (newNode->getkey() < curTree->getkey()) {
			newTree->ch[0] = insert(newTree->ch[0], newNode);
		} else {
			newTree->ch[1] = insert(newTree->ch[1], newNode);
		}
		newTree->update();
		return newTree;
	} else {
		newNode->update();
		auto it = split_val(newNode->getkey(), curTree);
		newNode->ch[0] = it.first;
		newNode->ch[1] = it.second;
		newNode->update();
		return newNode;
	}
}

treap* cap_sum(ll sum, treap* a) {
	if (a == nullptr) return nullptr;

	assert(0 <= sum);
	if (sum == 0) return nullptr;
	if (sum >= a->totsum) return a;

	if (sum < (a->ch[0] ? a->ch[0]->totsum : 0) + a->key) {
		return cap_sum(sum, a->ch[0]);
	}
	sum -= (a->ch[0] ? a->ch[0]->totsum : 0);

	treap* na = new treap(*a);

	if (sum <= na->cnt * na->key) {
		na->cnt = sum / na->key;
		assert(na->cnt);
		sum = 0;
	} else {
		sum -= na->cnt * na->key;
	}

	na->ch[1] = cap_sum(sum, na->ch[1]);
	na->update();
	return na;
}

const int MAXN = 1.1e5;
int N;
ll T;

ll X[MAXN];
ll S[MAXN];

int P[MAXN];
ll L[MAXN];

treap* treaps[MAXN];

ll V[MAXN][2];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		cin >> X[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
	}
	
	P[1] = 0;
	L[1] = 0;
	for (int i = 2; i <= N; i++) {
		cin >> P[i] >> L[i];
		L[i] *= 2;
		L[i] += L[P[i]];
	}

	for (int i = 1; i <= N; i++) {

		treap* newNode = new treap();
		newNode->key = S[i];
		newNode->cnt = X[i];
		newNode->update();
		treaps[i] = insert(treaps[P[i]], newNode);

		treaps[i] = cap_sum(T - L[i], treaps[i]);
		V[i][0] = V[i][1] = (treaps[i] ? treaps[i]->totcnt : 0);
		V[i][1] = V[i][1];
	}

	for (int i = N; i > 1; i--) {
		ll v = V[i][1];
		if (v >= V[P[i]][0]) {
			V[P[i]][1] = V[P[i]][0];
			V[P[i]][0] = v;
		} else if (v >= V[P[i]][1]) {
			V[P[i]][1] = v;
		}
	}

	cout << V[1][0] << '\n';

	return 0;
}