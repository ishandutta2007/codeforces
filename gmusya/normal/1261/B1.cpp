#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

struct que {
	ll k, pos, i;
};

struct sqrt_dec {
	vector <pair <ll, ll>> elements;
	ll max;
	ll next;
	ll prev;
};

ll n, k, head = -1, tail = 0;
vector <ll> a;
vector <sqrt_dec> arr;


void counting(ll cnt) {
	arr[cnt].max = 0;
	for (ll i = 0; i < arr[cnt].elements.size(); i++)
		arr[cnt].max = max(arr[cnt].max, arr[cnt].elements[i].second);
}

void split(ll num) {
	sqrt_dec new_chunk;
	new_chunk.next = arr[num].next;
	if (new_chunk.next != -1)
		arr[new_chunk.next].prev = tail;
	new_chunk.prev = num;
	arr[num].next = tail;
	for (ll i = arr[num].elements.size() / 2; i < arr[num].elements.size(); i++)
		new_chunk.elements.push_back(arr[num].elements[i]);
	arr[num].elements.resize(arr[num].elements.size() / 2);
	arr.push_back(new_chunk);
	counting(tail);
	counting(num);
	tail++;
}

void add(pair <ll, ll> elem) {
	ll cur_pos = 0, cnt = 0;
	while (cnt >= 0 && arr[cnt].max < elem.second) {
		if (arr[cnt].next == -1)
			break;
		cnt = arr[cnt].next;
	}
	arr[cnt].elements.push_back(elem);
	ll i;
	for (i = arr[cnt].elements.size() - 1; i > 0; i--)
		if (arr[cnt].elements[i].second < arr[cnt].elements[i - 1].second)
			swap(arr[cnt].elements[i], arr[cnt].elements[i - 1]);
	if (arr[cnt].elements.size() > 2 * arr.size())
		split(cnt);
}

ll query(ll pos) {
	ll request_answer = 0, cur_pos = 0, cnt = 0;
	while (cnt >= 0 && cur_pos + arr[cnt].elements.size() < pos) {
		cur_pos += arr[cnt].elements.size();
		cnt = arr[cnt].next;
	}
	return arr[cnt].elements[pos - cur_pos - 1].first;
}

bool cmp1(pair <ll, ll> a, pair <ll, ll> b) {
	return ((a.first > b.first) || (a.first == b.first && a.second < b.second));
}

bool cmp2(que a, que b) {
	return (a.k < b.k);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	arr.resize(1);
	arr[0].next = -1;
	tail = 1;
	ll n;
	cin >> n;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	vector <pair <ll, ll>> b(n);
	for (ll i = 0; i < n; i++) {
		b[i].first = a[i];
		b[i].second = i;
	}

	sort(b.begin(), b.end(), cmp1);

	ll m;
	cin >> m;
	vector <que> q(m);
	for (ll i = 0; i < m; i++) {
		cin >> q[i].k >> q[i].pos;
		q[i].i = i;
	}
	sort(q.begin(), q.end(), cmp2);

	vector <ll> ans(m);
	ll lul = 0;
	for (ll i = 0; i < m; i++) {
		while (lul < q[i].k) {
			add({ b[lul].first, b[lul].second });
			lul++;
		}
		ans[q[i].i] = query(q[i].pos);
	}

	for (ll i = 0; i < m; i++)
		cout << ans[i] << '\n';

	return 0;
}