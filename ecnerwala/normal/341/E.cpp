/*
LANG: C++
ID: he.andr1
PROG: 341E
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#include<string>
#include<cstring>
#include<cassert>
#include<numeric>
#include<complex>
#include<cmath>
#include<ctime>

using namespace std;

#define DEBUG 1

#ifdef DEBUG
	#define ERR cerr
#else
	#define ERR if(true); else cerr
#endif

#define ITER(i, v) for(__typeof(v.begin()) i = v.begin(); i != v.end(); i++) 
#define X real()
#define Y imag()
#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<int> pt;

template <class T> T cross(complex<T> a, complex<T> b) { return imag(a * conj(b)); }

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }

template <class T> void setmin(T &a, T b) { if(b < a) a = b; }
template <class T> void setmax(T &a, T b) { if(b > a) a = b; }

const int MAXN = 2000;
int N; 
int A[MAXN];

vector<pii> moves;

//move from j to i
int move(int i, int j){
	moves.push_back(pii(i + 1, j + 1));
	assert(A[j] >= A[i]);
	A[j] -= A[i];
	A[i] *= 2;
}

void go3(int i, int j, int k) {
	//cerr << i << ' ' << j << ' ' << k << '\n';
	//cerr << A[i] << ' ' << A[j] << ' ' << A[k] << '\n';

	//fast bubblesort
	if(A[i] > A[j]) swap(i, j);
	if(A[j] > A[k]) swap(j, k);
	if(A[i] > A[j]) swap(i, j);

	if(A[i] == 0) return;

	while(A[j] >= A[i]) {
		if((A[j] / A[i]) % 2) move(i, j);
		else move(i, k);
	}

	go3(i, j, k);
}

int go() {
	int cnt = 0;
	for(int i = 0; i < N; i++) cnt += (A[i] > 0);

	if(cnt < 2) {
		return -1;
	}
	
	while(cnt > 2) {
		int i = 0;
		while(A[i] == 0) i++;
		int j = i + 1;
		while(A[j] == 0) j++;
		int k = j + 1;
		while(A[k] == 0) k++;

		go3(i, j, k);
		
		cnt --;
	}

	return moves.size();
}

void io() {
	cin >> N;
	for(int i = 0; i < N; i++) cin >> A[i];
	cout << go() << '\n';

	ITER(i, moves) {
		cout << i->A << ' ' << i->B << '\n';
	}
}

int main() {
	io();
	return 0;
}