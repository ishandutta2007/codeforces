/*input
2 100
2 42
2 58
*/
#include <bits/stdc++.h>

using namespace std;

struct iss {
	int i, second;
	long long first;
};
//sum
struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	long long sum = 0;
	int blog = 0;
	void print() {
		if (left)
			left->print();

		//cout << from << " " << to << " " << sum << " " << blog << endl;

		if (right)
			right->print();
	}
	Node(int from, int to, iss mas[]): from(from), to(to) {
		if (from == to) {
			sum = mas[from].first;
			return;
		}

		left = new Node(from, (from + to) / 2, mas);
		right = new Node((from + to) / 2 + 1, to, mas);
		sum = left->sum + right->sum;
	}
	void update(int in) {
		if (from == to) {
			sum = 0;
			blog = 1;
			return;
		}

		if (in <= left->to)
			left->update(in);
		else
			right->update(in);

		sum = left->sum + right->sum;
		blog = left->blog + right->blog;
	}
	int find(long long didz) {
		if (from == to) {
			if (sum > didz)
				return 0;
			else
				return to - from + 1 - blog;
		}

		if (sum - right->sum > didz)
			return left->find(didz);

		return left->to - left->from + 1 - left->blog + right->find(didz - (sum - right->sum));
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	long long t;
	cin >> n >> t;
	iss mas[n];

	for (int i = 0; i < n; i++) {
		cin >> mas[i].second >> mas[i].first;
		mas[i].i = i + 1;
	}

	sort(mas, mas + n, [](const auto & i, const auto & j) -> bool {
		return i.first < j.first;
	});

	Node medis(0, n - 1, mas);

	vector<int> pos[n + 1];

	for (int i = 0; i < n; i++)
		pos[mas[i].second].push_back(i);

	int ats = 0;

	for (int i = 1; i <= n; i++) {
		//cout << min(medis.find(t), i) << endl;
		ats = max(ats, min(medis.find(t), i));

		for (auto && x : pos[i]) {
			//cout << "R " << x << endl;
			medis.update(x);
		}
	}

	cout << ats << endl << ats << endl;
	int kie = 0;

	for (int i = 0; i < n and kie < ats; i++) {
		if (mas[i].second >= ats) {
			cout << mas[i].i << " ";
			kie++;
		}
	}


	return 0;
}