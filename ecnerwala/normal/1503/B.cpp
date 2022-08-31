#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<array<int, 2>> evens; evens.reserve((N*N+1)/2);
	vector<array<int, 2>> odds; odds.reserve(N*N/2);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i^j)&1) odds.push_back({i+1,j+1});
			else evens.push_back({i+1,j+1});
		}
	}

	int ce = 0;
	int ie = 0;
	int co = 1;
	int io = 0;
	for (int z = 0; z < N*N; z++) {
		int a; cin >> a;
		if (ie == int(evens.size())) {
			int v = 1;
			while (v == a || v == ce) v++;
			co = v;
			cout << co << ' ' << odds[io][0] << ' ' << odds[io][1] << '\n';
			io++;
		} else if (io == int(odds.size())) {
			int v = 1;
			while (v == a || v == co) v++;
			ce = v;
			cout << ce << ' ' << evens[ie][0] << ' ' << evens[ie][1] << '\n';
			ie++;
		} else if (ce != 0 && a != co) {
			if (!co) {
				co = 1;
				while (co == a || co == ce) co++;
			}
			cout << co << ' ' << odds[io][0] << ' ' << odds[io][1] << '\n';
			io++;
			if (io - ie == N) ce = 0;
		} else if (co != 0 && a != ce) {
			if (!ce) {
				ce = 1;
				while (ce == a || ce == co) ce++;
			}
			cout << ce << ' ' << evens[ie][0] << ' ' << evens[ie][1] << '\n';
			ie++;
			if (ie - io == N) co = 0;
		} else assert(false);
		cout << flush;
	}

	return 0;
}

// Bob can never place 2 unequal cells diagonally adjacent