#include <cstdio>

using namespace std;

const int N = 1000010;

int n;
bool fw[N];

int lowBit(int k) { return k & -k; }
void change(int k);
bool query(int k);

int main() {
	scanf("%d", &n);
	bool f = false;
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		f ^= query(x);
		change(x);
	}
	puts(((f ^ n) & 1) ? "Um_nik" : "Petr");
	return 0;
}

void change(int k) {
	for (; k; k -= lowBit(k))
		fw[k] = !fw[k];
}

bool query(int k) {
	bool ret = false;
	for (; k <= n; k += lowBit(k))
		ret ^= fw[k];
	return ret;
}