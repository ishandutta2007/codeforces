/*input
4
6 3 1 2

*/
#include <bits/stdc++.h>

using namespace std;

template<class T>
struct Set {
	struct Node {
		T val;
		int size;
		Node *left = NULL, *right = NULL;
		Node(const T &a): val(a), size(1) {}
	};
	Node *root = NULL;

	int getSize(Node *&d) {
		return d == NULL ? 0 : d->size;
	}

	int maziaulygu(Node *&d) {
		return 1 + getSize(d->left);
	}

	void updateSize(Node *&d) {
		d->size = 1 + getSize(d->left) + getSize(d->right);
	}

	void rotateleft(Node *&d) {
		if (d == NULL or d->right == NULL)
			return;

		Node *dab = d;
		d = d->right;
		Node *temp = d->left;
		d->left = dab;
		d->left->right = temp;

		updateSize(d->left);
		updateSize(d);
	}

	void rotateright(Node *&d) {
		if (d == NULL or d->left == NULL)
			return;

		Node *dab = d;
		d = d->left;
		Node *temp = d->right;
		d->right = dab;
		d->right->left = temp;

		updateSize(d->right);
		updateSize(d);
	}

	bool insert(Node *&d, const T &val) {
		if (d == NULL) {
			d = new Node(val);
			return true;
		}

		if (d->val == val)
			return false;

		bool ar = false;

		if (d->val < val)
			ar = insert(d->right, val);
		else
			ar = insert(d->left, val);

		d->size += ar;

		if (ar) {
			if (d->size / 2 + 1 < maziaulygu(d))
				rotateright(d);
			else if (d->size / 2 - 1 > maziaulygu(d))
				rotateleft(d);
		}

		return ar;
	}

	int find(Node *&d, const T &val) {
		if (d == NULL)
			return false;

		if (d->val == val)
			return maziaulygu(d);

		if (d->val < val)
			return maziaulygu(d) + find(d->right, val);
		else
			return find(d->left, val);
	}

	int find(const T &val) {
		return find(root, val);
	}

	bool insert(const T &val) {
		return insert(root, val);
	}

	int size() {
		return getSize(root);
	}
};

long long solve(vector<long long> kort) {
	long long n = kort.size();
	pair<long long, long long> mas[n];

	for (long long i = 0; i < n; i++) {
		mas[i].first = kort[i];
		mas[i].second = i;
	}

	sort(mas, mas + n);

	long long last = -1;
	long long ats = 0;

	Set<long long>pas;
	int lastvien = -1;

	for (long long i = 0; i < n; i++) {
		if (mas[i].first != lastvien) {
			lastvien = mas[i].first;
			int iki = i;

			vector<pair<long long, long long>>did, maz;

			while (iki < n and mas[iki].first == lastvien) {
				if (mas[iki].second < last)
					maz.push_back(mas[iki]);
				else
					did.push_back(mas[iki]);

				iki++;
			}

			int poin = i;

			for (int j = 0; j < did.size(); j++)
				mas[poin++] = did[j];

			for (int j = 0; j < maz.size(); j++)
				mas[poin++] = maz[j];
		}

		long long dab = mas[i].second;

		if (last < dab)
			ats += dab - last - (pas.find(dab - 1) - pas.find(last));
		else
			ats += n - last + dab - (pas.find(n - 1) - pas.find(last)) - (pas.find(dab - 1));

		//cout <<dab << " " << ats << endl;

		last = dab;
		pas.insert(dab);
	}

	return ats;
}
/*
long long solve2(vector<long long> kort) {
	deque<long long>kort2;
	long long n = kort.size();

	for (int i = 0; i < n; i++)
		kort2.push_back(kort[i]);

	long long c = 0;

	while (kort2.size() > 0) {
		if ((*min_element(kort2.begin(), kort2.end())) == kort2[0])
			kort2.pop_front();
		else {
			kort2.push_back(kort2[0]);
			kort2.pop_front();
		}

		c++;
	}

	return c;
}
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	long long n;
	cin >> n;
	vector<long long> kort(n);

	for (long long i = 0; i < n; i++){
		cin >> kort[i];
	}

	cout << solve(kort)/* << " " << solve2(kort)*/;

	return 0;
}