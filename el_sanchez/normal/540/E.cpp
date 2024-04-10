#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 400500;

int n;
int a[MAXN], b[MAXN], pa, pb;
int w[MAXN], sz;
int A[MAXN], W[MAXN], AA[MAXN], WW[MAXN], SW[MAXN];
set<int> used;            
map<int, int> pos;
ll answer = 0;

void mergeSort(int l, int r) {
	if (l == r)
		return;
	if (l + 1 == r) {
		if (A[l] > A[r]) {
			answer += 1ll * W[l] * W[r];
			swap(A[l], A[r]);
			swap(W[l], W[r]);
			return;
		}
	}

	mergeSort(l, (l + r) >> 1);
	mergeSort(((l + r) >> 1) + 1, r);

	int p0 = l, p1 = ((l + r) >> 1) + 1;
	int r0 = p1, r1 = r + 1, pos = l;
	
	SW[p1 - 1] = W[p1 - 1];
	for (int i = p1 - 2; i >= p0; i--)
		SW[i] = SW[i + 1] + W[i];
		 
	//cout << p0 << ' ' << r0 << ' ' << p1 << ' ' << r1 << '\n';
	while (p0 < r0 && p1 < r1) {
		if (A[p0] > A[p1]) {
			answer += 1ll * SW[p0] * W[p1];
			AA[pos] = A[p1];
			WW[pos] = W[p1];
			p1++;	
		} else {
			AA[pos] = A[p0];
			WW[pos] = W[p0];
			p0++;	
		}
		pos++;		
	}
	
	while (p0 < r0) {
		AA[pos] = A[p0];
		WW[pos] = W[p0];
		p0++;
		pos++;			
	}
	while (p1 < r1) {
		AA[pos] = A[p1];
		WW[pos] = W[p1];
		p1++;
		pos++;			
	}
	for (int i = l; i <= r; i++) {
		A[i] = AA[i];
		W[i] = WW[i];	
	}
}

int main() {
                              
    cin >> n;
    forn(i, n) {
    	cin >> a[i] >> b[i];
    	used.insert(a[i]);
    	used.insert(b[i]);
    }
    used.insert(1);
    
    int ptr = 0;
    sz = 0;
    for (auto k: used) {
    	if (ptr < k) {
    		w[sz++] = k;
    		w[sz++] = k + 1;
    		ptr = k + 1;	
    	} else if (ptr <= k) {
    		w[sz++] = k + 1;
    		ptr = k + 1;
    	}
    }
    if (used.find(w[sz - 1]) == used.end()) {
    	sz--;
    } else {
    	w[sz] = w[sz - 1] + 1;	
    }
    
    int sum = 0;
    for (int i = 0; i < sz; i++) {
    	A[i] = w[i];
    	W[i] = w[i + 1] - w[i];
    	sum += W[i];
    	pos[sum] = i;
    }
   	
    forn(i, n) {
    	pa = pos[a[i]];
    	pb = pos[b[i]];
    	swap(A[pa], A[pb]);
    }    	
    
    //forn(i, sz)
    //	cout << A[i] << ' ' << W[i] << '\n';
    mergeSort(0, sz - 1);
    //forn(i, sz)
    //	cout << A[i] << ' ' << W[i] << '\n';
    cout << answer << '\n';
	return 0;
}