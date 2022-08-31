#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

// #define TEST

#ifdef TEST
const vector<int> guessed = {2, 0, 2, 0};
const int g_n = guessed.size();
vector<int> g_cur = guessed;
#endif

struct Info {
	int choose;
	int conseq;
};

Info operator -(const Info& fst, const Info& snd) {
	return {fst.choose - snd.choose, fst.conseq - snd.conseq};
}

Info readInfo() {
	int x = nxt(), y = nxt();
	return {x, y};
}

Info initial;
Info last;
Info delta;
vector<Info> history;

void ask(int pos) {
#ifdef TEST
	g_cur[pos] += 1;
	int ch = 0, co = 0;
	for (int i = 0; i < g_n; ++i) {
		ch += g_cur[i] * (g_cur[i] - 1) * (g_cur[i] - 2) / 6;
	}
	for (int i = 0; i + 3 <= g_n; ++i) {
		co += g_cur[i] * g_cur[i + 1] * g_cur[i + 2];
	}
	Info fresh = {ch, co};
#else
	cout << "+ " << pos + 1 << endl;
	Info fresh = readInfo();
#endif
	history.push_back(delta = fresh - last);
	last = fresh;
}

map<int, int> by_choose;

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	for (int i = 1; i < 1000; ++i) {
		by_choose[i * (i - 1) / 2] = i;
	}

#ifdef TEST
	int n = g_n;
	{
		int ch = 0, co = 0;
		for (int i = 0; i < g_n; ++i) {
			ch += g_cur[i] * (g_cur[i] - 1) * (g_cur[i] - 2) / 6;
		}
		for (int i = 0; i + 3 <= g_n; ++i) {
			co += g_cur[i] * g_cur[i + 1] * g_cur[i + 2];
		}
		last = initial = {ch, co};
	}
#else
	int n = nxt();
	last = initial = readInfo();
#endif
	vector<int> ans(n, -1);
	vector<int> a(n, -1);

	ask(0);
	if (delta.choose) {
		ans[0] = by_choose[delta.choose];
		a[0] = ans[0] + 1;
	}
	bool is_zero_among_12 = (delta.conseq == 0);
	ask(1);
	if (initial.conseq == last.conseq) {
		ans[2] = a[2] = 0;
	}
	if (delta.choose) {
		ans[1] = by_choose[delta.choose];
		a[1] = ans[1] + 1;
	}

	bool is_2_pressed = false;
	if (a[0] == -1 && a[1] == -1) {
		if (!is_zero_among_12) {
			ans[1] = 1;
			a[1] = 2;
			ask(0);
			ans[0] = by_choose[delta.choose] - 1;
			a[0] = ans[0] + 2;
		} else if (a[2] != 0) {
			ans[1] = 0;
			a[1] = 1;
			ask(0);
			ans[0] = by_choose[delta.choose] - 1;
			a[0] = ans[0] + 2;
		} else {
			ask(2);
			a[2] = 1;
			int conseq_after_2 = delta.conseq;
			ask(0);
			ans[0] = by_choose[delta.choose] - 1;
			a[0] = ans[0] + 2;
			a[1] = delta.conseq;
			ans[1] = a[1] - 1;
			if (conseq_after_2 == (a[0] - 1) * a[1]) {
				ans[3] = a[3] = 0;
			}
			is_2_pressed = true;
		}
	} else if (a[0] == -1) {
		ask(0);
		ans[0] = by_choose[delta.choose] - 1;
		a[0] = ans[0] + 2;
	} else if (a[1] == -1) {
		ask(1);
		ans[1] = by_choose[delta.choose] - 1;
		a[1] = ans[1] + 2;
	}

	for (int i = (is_2_pressed ? 3 : 2); i < n - 1; ++i) {
		if (a[i] == 0) {
			ask(i);
			++a[i];
		} else {
			ask(i);
			ans[i] = by_choose[delta.choose];
			a[i] = ans[i] + 1;
		}
		if (delta.conseq == a[i - 2] * a[i - 1]) {
			ans[i + 1] = a[i + 1] = 0;
		}
	}

	if (is_2_pressed && n == 4) {
		a[3] = ans[3] = (history[2].conseq - (ans[0] + 1) * (ans[1] + 1)) / (ans[1] + 1);
	} else {
		ans[n - 1] = a[n - 1] = (delta.conseq - a[n - 3] * a[n - 4]) / a[n - 3];
	}
#ifdef TEST
	if (ans != guessed) {
		cerr << "fail\n   your answer:";
		for (int x : ans) {
			cerr << " " << x;
		}
		cerr << "\ncorrect answer:";
		for (int x : guessed) {
			cerr << " " << x;
		}
		cerr << "\n";
	} else {
		cerr << "ok";
		for (int x : guessed) {
			cerr << " " << x;
		}
		cerr << "\n";
	}
#else
	cout << "!";
	for (int x : ans) {
		cout << " " << x;
	}
	cout << endl;
#endif

	return 0;
}