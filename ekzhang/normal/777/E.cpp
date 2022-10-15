#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
#define MAX 200013
#define MAXSEG 524288
int N;
long long st[MAXSEG];
set<int> compress;
map<int, int> compressf;
int A[MAXN];
int B[MAXN];
int H[MAXN];
int o[MAXN];

void update(int i, long long x, int lo=0, int hi=MAX, int node=0) {
	if (lo > i || hi < i) return;
	if (lo == hi) { st[node] = max(st[node], x); return; }
	int mid = (lo + hi) / 2;
	update(i, x, lo, mid, 2 * node + 1);
	update(i, x, mid + 1, hi, 2 * node + 2);
	st[node] = max(st[2 * node + 1], st[2 * node + 2]);
}

long long query(int s, int e, int lo=0, int hi=MAX, int node=0) {
	if (lo > e || hi < s) return 0;
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return max(query(s, e, lo, mid, 2 * node + 1), query(s, e, mid + 1, hi, 2 * node + 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> H[i];
		compress.insert(A[i]);
		compress.insert(B[i]);
	}

	int t = 0;
	for (int x : compress) {
		compressf[x] = t++;
	}

	for (int i = 0; i < N; i++) {
		A[i] = compressf[A[i]];
		B[i] = compressf[B[i]];
	}

	for (int i = 0; i < N; i++) o[i] = i;
	sort(o, o + N, [](int i, int j) {
		return B[i] == B[j] ? A[i] < A[j] : B[i] < B[j];
	});
	
	for (int idx = 0; idx < N; idx++) {
		int i = o[idx];
		update(B[i], H[i] + query(A[i] + 1, B[i]));
	}

	cout << query(0, MAX) << endl;
	return 0;
}