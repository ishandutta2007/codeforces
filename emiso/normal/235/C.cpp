#include <bits/stdc++.h>

using namespace std;

#define MN 1000100 // 2*MAXN
#define ALP 26

// macacario
struct SuffixAutomaton {
	int len[2*MN], link[2*MN], cnt[2*MN];
	int nxt[2*MN][ALP], sz, last, root;
	int newnode() {
		int x = ++sz;
		len[x] = 0; link[x] = -1; cnt[x] = 1;
		for(int c = 0; c < ALP; c++) nxt[x][c] = 0;
		return x;
	}
	inline int reduce(char c) { return c - 'a'; }

	SuffixAutomaton() { clear(); }
	void clear() {
		sz = 0;
		root = last = newnode();
	}
	void insert(string& s) {
		for(char &c : s)
            extend(reduce(c));
	}
	void extend(int c) {
		int cur = newnode(), p;
		len[cur] = len[last] + 1;
		for(p = last; p != -1 && !nxt[p][c]; p = link[p]) {
			nxt[p][c] = cur;
		}
		if (p == -1) link[cur] = root;
		else {
			int q = nxt[p][c];
			if (len[p] + 1 == len[q]) link[cur] = q;
			else {
				int clone = newnode();
				len[clone] = len[p] + 1;
				for(int i = 0; i < ALP; i++)
					nxt[clone][i] = nxt[q][i];
				link[clone] = link[q];
				cnt[clone] = 0;
				while(p != -1 && nxt[p][c] == q) {
					nxt[p][c] = clone;
					p = link[p];
				}
				link[q] = link[cur] = clone;
			}
		}
		last = cur;
	}

	int deg[2*MN];
	void computeCnt() {
		fill(deg, deg+sz+1, 0);
		for(int i = root+1; i <= sz; i++)
			deg[link[i]]++;
		queue<int> q;
		for(int i = root+1; i <= sz; i++)
			if (deg[i] == 0) q.push(i);
		while(!q.empty()) {
			int i = q.front(); q.pop();
			if (i <= root) continue;
			int j = link[i];
			cnt[j] += cnt[i];
			if ((--deg[j]) == 0) q.push(j);
		}
	}
	int nmatches(string& s) {
		int p = root;
		for(int i = 0; i < s.size(); i++) {
			int c = reduce(s[i]);
			if (!nxt[p][c]) return 0;
			p = nxt[p][c];
		}
		return cnt[p];
	}
} SA;

int n, sz;
char s[1000100];
string str, pat;

void z_function(string &s, int *z) {
    for(int i = 1, L = 0, R = 0; i < s.size(); i++) {
        if(i > R) L = R = i;
        z[i] = min(R-i, z[i-L]);
        while(i + z[i] < s.size() && s[z[i]] == s[i+z[i]]) z[i]++;
        if(i + z[i] > R) L = i, R = i + z[i];
    }
}
int z[2000100];

bool ok(int id) {
    return (id < sz || z[id-sz+1] < sz);
}

int main() {
    scanf("%s", s);
    str = s;
    SA.insert(str);
    SA.computeCnt();

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        pat = s;
        sz = pat.size();
        pat += pat;
        pat.pop_back();
        z_function(pat, z);

        int ans = 0, v = 1, l = 0;
        for(int j = 0; j < pat.size(); j++) {
            int idx = pat[j] - 'a';
            while(v > 1 && (!SA.nxt[v][idx] || SA.len[SA.link[v]] >= sz - 1)) {
                v = SA.link[v];
                l = SA.len[v];
            }
            if(SA.nxt[v][idx]) {
                v = SA.nxt[v][idx];
                l++;
            }
            if(!ok(j)) {
                // cerr << "Cycle at " << j << endl;
                break;
            }
            if(l >= sz) ans += SA.cnt[v];
        }
        printf("%d\n", ans);
    }
	return 0;
}