#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <unordered_map>

#define endl '\n'

using namespace std;

struct chunk {
	vector <int> cnt, val;
};

int n, q, X;
vector <int> a;
vector <chunk> sqrt_dec;

void build_sqrt_dec() {
	int X = ceil(sqrt(n));
	sqrt_dec.resize(X);
	for (int i = 0; i < X; i++) {
		sqrt_dec[i].cnt.resize(1e5 + 1);
		sqrt_dec[i].val.resize(0);
		for (int j = 0; j < X && i * X + j < n; j++) {
			sqrt_dec[i].cnt[a[i * X + j]]++;
			sqrt_dec[i].val.push_back(a[i * X + j]);
		}
	}
}

int query(int l, int r, int k) {
	int cur_pos = 0, i = 0, ans = 0;
	while (cur_pos + sqrt_dec[i].val.size() <= l) {
		cur_pos += sqrt_dec[i].val.size();
		i++;
	}
	//1st case: l.chunk == r.chunk
	if (cur_pos + sqrt_dec[i].val.size() > r) {
		for (int j = l - cur_pos; j <= r - cur_pos; j++)
			ans += (sqrt_dec[i].val[j] == k);
		return ans;
	}
	//2nd case: l.chunk < r.chunk
	for (int j = l - cur_pos; j < sqrt_dec[i].val.size(); j++)
		ans += (sqrt_dec[i].val[j] == k);
	cur_pos += sqrt_dec[i].val.size();
	i++;
	while (cur_pos + sqrt_dec[i].val.size() <= r) {
		ans += sqrt_dec[i].cnt[k];
		cur_pos += sqrt_dec[i].val.size();
		i++;
	}
	for (int j = 0; j <= r - cur_pos; j++)
		ans += (sqrt_dec[i].val[j] == k);
	return ans;
}

void rebuild_sqrt_dec() {
	int it = 0, cur_first = 0;
	for (int i = 0; i < n; i++) {
		while (i >= sqrt_dec[it].val.size() + cur_first) {
			cur_first += sqrt_dec[it].val.size();
			it++;
		}
		a[i] = sqrt_dec[it].val[i - cur_first];
		sqrt_dec[it].cnt[a[i]]--;
	}
	build_sqrt_dec();
}


void insert(int pos, int val) {
	int i = 0, cur_pos = 0;
	while (cur_pos + sqrt_dec[i].val.size() <= pos) {
		cur_pos += sqrt_dec[i].val.size();
		i++;
	}
	sqrt_dec[i].val.push_back(0);
	for (int j = sqrt_dec[i].val.size() - 1; j > pos - cur_pos; j--)
		sqrt_dec[i].val[j] = sqrt_dec[i].val[j - 1];
	sqrt_dec[i].val[pos - cur_pos] = val;
	sqrt_dec[i].cnt[val]++;
}

int erase(int pos) {
	int i = 0, cur_pos = 0, ans;
	while (cur_pos + sqrt_dec[i].val.size() <= pos) {
		cur_pos += sqrt_dec[i].val.size();
		i++;
	}
	ans = sqrt_dec[i].val[pos - cur_pos];
	for (int j = pos - cur_pos; j < sqrt_dec[i].val.size() - 1; j++)
		sqrt_dec[i].val[j] = sqrt_dec[i].val[j + 1];
	sqrt_dec[i].val.resize(sqrt_dec[i].val.size() - 1);
	sqrt_dec[i].cnt[ans]--;
	return ans;
}

void write() {
	int i = 0;
	while (i < X) {
		cout << i << ": ";
		for (auto now : sqrt_dec[i].val)
			cout << now << " ";
		cout << endl;
		i++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build_sqrt_dec();
	cin >> q;
	int last_ans = 0, cnt = 0;
	vector <int> answer;
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int _l, _r, l, r;
			cin >> _l >> _r;
			l = ((_l + last_ans - 1) % n);
			r = ((_r + last_ans - 1) % n);
			if (l > r)
				swap(l, r);
			if (l != r) {
				int num = erase(r);
				insert(l, num);
			}
			cnt++;
			if (cnt % 310 == 0)
				rebuild_sqrt_dec();
			//write();
		}
		if (type == 2) {
			int _l, _r, _k, l, r, k;
			cin >> _l >> _r >> _k;
			l = ((_l + last_ans - 1) % n);
			r = ((_r + last_ans - 1) % n);
			k = ((_k + last_ans - 1) % n) + 1;
			if (l > r)
				swap(l, r);
			last_ans = query(l, r, k);
			answer.push_back(last_ans);
		}
	}
	for (auto now : answer)
		cout << now << endl;
	return 0;
}