#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

char buf[110];
int n, m;
string w[50];
int p[50], res[50], qz[50], qp[50];
map<string, int> all;

bool cmp1(int i, int j){
	if (res[i] != res[j]) return res[i] > res[j];
	if (qz[i] - qp[i] != qz[j] - qp[j]) return qz[i] - qp[i] > qz[j] - qp[j];
	return qz[i] > qz[j];
}

bool cmp2(int i, int j) {
	return w[i] < w[j];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &buf);
		w[i] = buf;
		all[w[i]] = i;
		p[i] = i;
	}
	gets(buf);
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		gets(buf);
		int len = strlen(buf);
		for (int j = 0; j < len; j++){
			if (buf[j] == '-' || buf[j] == ':') buf[j] = ' ';
		}
		char T1[110], T2[110];
		int x, y;
		sscanf(buf, "%s %s %d %d", &T1, &T2, &x, &y);
		string a = T1, b = T2;
		int A = all[a];
		int B = all[b];
		if (x > y) res[A] += 3;
		else if (x < y) res[B] += 3;
		else res[A]++, res[B]++;
		qz[A] += x, qp[B] += x, qz[B] += y, qp[A] += y;
	}
	sort(p, p + n, cmp1);
	sort(p, p + n / 2, cmp2);
	for (int i = 0; i < n / 2; i++){
		cout << w[p[i]] << endl;
	}
	return 0;
}