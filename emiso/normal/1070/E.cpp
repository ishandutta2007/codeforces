#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll c, n, m, t, p[200200];
vector < int > vpos[200200];

ll bit[2][200200];

void update(int t, int pos, int val) {
	while (pos <= n) {
		bit[t][pos] += val;
		pos += pos & -pos;
	}
}

ll query(int t, int pos) {
	ll ret = 0;
	while (pos) {
		ret += bit[t][pos];
		pos -= pos & -pos;
	}
	return ret;
}

int prefix(int t, int k) {
	int pos = 0, pot = 0;
	while ((1 << (pot+1)) <= n+1) pot++;
	while (pot >= 0) {
		int size = (1 << pot);
		if (pos + size <= n && bit[t][pos + size] <= k) {
			k -= bit[t][pos+size];
			pos += size;
		}
		pot--;
	}
	return pos;
}

int main() {
	scanf("%lld", &c);
	while (c--) {
		scanf("%lld %lld %lld", &n, &m, &t);
		set < int > vals;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &p[i]);
			vals.insert(p[i]);
			vpos[p[i]].push_back(i);
		}
		
		int quant = 0, d = 1;
		for (int v : vals) {
			for (int i = 0; i < vpos[v].size(); i++) {
				update(0, vpos[v][i]+1, v);
				update(1, vpos[v][i]+1, 1);
			}
			
			int ini = 1, fim = n;
			while (ini <= fim) {
				int meio = (ini+fim)/2;
				ll sum = query(0, meio), q = query(1, meio);
				if (q % m) q -= q%m;
				else q -= m;
				
				int pos = prefix(1, q);
				sum += query(0, pos);
				
				if (sum <= t) ini = meio+1;
				else fim = meio-1;
			}
			
			if (query(1, fim) > quant) {
				quant = query(1, fim);
				d = v;
			}
		}
		
		printf("%d %d\n", quant, d);
		
		for (int i = 0; i <= n; i++) {
			vpos[p[i]].clear();
			bit[0][i] = bit[1][i] = 0;
		}
	}
	return 0;
}