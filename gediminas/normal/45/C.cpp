/*input
4
BGBG
4 2 4 3
*/
#include <bits/stdc++.h>

using namespace std;

struct Mok {
	int skil;
	bool lyt;
	int i;
	bool pan = false;
	list<Mok *>::iterator it;
};

struct Pora {
	int del;
	int i, j;
	Mok *a, *b;
	bool operator<(const Pora &o)const {
		if (del == o.del)
			return i < o.i;

		return del < o.del;
	}
	Pora(Mok *x, Mok *y) {
		i = x->i;
		j = y->i;
		del = abs(x->skil - y->skil);
		a = x, b = y;
	}
};

int main () {
	int n;
	cin >> n;
	string a;
	cin >> a;

	list<Mok *> mok;

	for (int i = 0; i < n; i++) {
		Mok *x = new Mok;
		x->lyt = a[i] == 'B';
		cin >> x->skil;
		x->i = i;
		mok.push_back(x);
		x->it = --mok.end();
	}

	multiset<Pora> b;

	for (list<Mok *>::iterator i = mok.begin(); i != --mok.end(); i++) {
		list<Mok *>::iterator j = i;
		j++;
		//cout << i->lyt << " " << j->lyt << endl;

		if ((*i)->lyt != (*j)->lyt)
			b.insert(Pora(*i, *j));
	}

	vector<pair<int, int>> ats;

	while (b.size() > 0) {
		Pora p = *b.begin();
		b.erase(b.begin());

		if (p.a->pan or p.b->pan)
			continue;

		ats.push_back(make_pair(p.i + 1, p.j + 1));

		p.a->pan = true;
		p.b->pan = true;
		//cout << p.i << " " << p.j << endl;

		list<Mok *>::iterator i = p.a->it;
		list<Mok *>::iterator j = p.b->it;

		if (i == mok.begin() or j == --mok.end()) {
			mok.erase(i);
			mok.erase(j);
			continue;
		}

		i--;
		j++;

		mok.erase(p.a->it);
		mok.erase(p.b->it);

		if ((*i)->lyt != (*j)->lyt)
			b.insert(Pora(*i, *j));
	}

	cout << ats.size() << "\n";

	for (auto && x : ats)
		cout << x.first << " " << x.second << "\n";


	return 0;
}