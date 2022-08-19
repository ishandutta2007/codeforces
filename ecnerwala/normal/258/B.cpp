/*
ID: he.andr1
PROG: PrB
LANG: C++
*/

#include<iostream>
#include<fstream>

using namespace std;

const int N = 10, MOD = 1000000007, C = 7;

long m, pow10[N], pow2[N], pow8[N], numLucky[N], pascal[N][N];

long long go() {
	m++;
	for(int i = 0; i < N; i++) {
		pascal[i][i] = 1;
		pascal[i][0] = 1;
	}
	for(int i = 1; i < N; i++) {
		for(int j = 1; j <= i; j++) {
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
		}
	}
	pow10[0] = 1;
	pow2[0] = 1;
	pow8[0] = 1;
	int maxPow = 0;
	for(int i = 1; i < N; i++) {
		pow10[i] = (pow10[i - 1] * 10) % MOD;
		if(pow10[i] <= m) maxPow = i;
		pow2[i] = (pow2[i - 1] * 2) % MOD;
		pow8[i] = (pow8[i - 1] * 8) % MOD;
	}
	for(int i = 0; i < N; i++) {
		numLucky[i] = 0;
	}
	int plus = 0;
	for(int p = maxPow; p >= 0; p--) {
		int d = m/pow10[p];
		int unlucky = d;
		int lucky = 0;
		if(d > 4) {
			unlucky --;
			lucky++;
			if(d > 7) {
				unlucky --;
				lucky++;
			}
		}
		for(int i = 0; i <= p; i++) {
			int c = pow2[i] * pow8[p - i];
			c %= MOD;
			c *= pascal[p][i];
			c %= MOD;
			numLucky[plus + i] += unlucky * c;
			numLucky[plus + i] %= MOD;
			numLucky[plus + i + 1] += lucky * c;
			numLucky[plus + i + 1] %= MOD;
		}
		m %= pow10[p];
		if(d == 4 || d == 7) plus ++;
	}
	numLucky[0] --; // 0 is not a valid number
//	for(int i = 0; i < N; i++) cout << numLucky[i] << ' ';
//	cout << '\n';
	long long out = 0, count = 0; 
	for(int i = 1; i < N && numLucky[i] > 0; i++) {
		for(int a = 0; a < i; a++) {
			for(int b = 0; a + b < i; b++) {
				for(int c = 0; a + b + c < i; c++) {
					for(int d = 0; a + b + c + d < i; d++) {
						for(int e = 0; a + b + c + d + e < i; e++) {
							int f = i - 1 - a - b - c - d - e;
//							cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
							int frq[N];
							for(int i = 0; i < N; i++) frq[i] = 0;
							long long cur = 1;
							cur *= numLucky[a] - frq[a];
							cur %= MOD;
							frq[a] ++;
							cur *= numLucky[b] - frq[b];
							cur %= MOD;
							frq[b] ++;
							cur *= numLucky[c] - frq[c];
							cur %= MOD;
							frq[c] ++;
							cur *= numLucky[d] - frq[d];
							cur %= MOD;
							frq[d] ++;
							cur *= numLucky[e] - frq[e];
							cur %= MOD;
							frq[e] ++;
							cur *= numLucky[f] - frq[f];
							cur %= MOD;
							frq[f] ++;
							count += cur;
							count %= MOD;
						}
					}
				}
			}
		}
		out += count * numLucky[i];
		out %= MOD;
	}
	return out;
}

void io(istream &in, ostream &out) {
	in >> m;
	out << go() << '\n';
}

int main(){
//	ifstream fin ("PrB.in");
//	if(fin.good()) {
//		ofstream fout ("PrB.out");
//		io(fin, fout);
//		fout.close();
//	} else 
		io(cin, cout);
	return 0;
}