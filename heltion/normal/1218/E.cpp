//Author: Heltion
//Date: 09-17-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 24000;
namespace NTT{
	using P = vector<LL>;
	constexpr LL mod = 998244353;
	constexpr LL G = 3;
	vector<int> rev;
	void add(LL &a, LL b){
		a += b;
		if(a >= mod) a -= mod;
	}
	void sub(LL &a, LL b){
		a -= b;
		if(a < 0) a += mod;
	}
	void mul(LL &a, LL b){
		a = a * b % mod;
	}
	LL power(LL a, LL r){
		LL res = 1;
		for(; r; r >>= 1, mul(a, a))
			if(r & 1) mul(res, a);
		return res;
	}
	void frev(int n){
		if((int)rev.size() == n) return;
		rev.resize(n);
		for(int i = 0; i < n; i += 1) rev[i] = i ? rev[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0) : 0;
	}
	void DFT(P& v, bool inv = false){
		int n = v.size();
		frev(n);
		LL* a = v.data();
		for(int i = 0; i < n; i += 1) if(i < rev[i]) swap(a[i], a[rev[i]]);
		for(int m = 1; m <= n >> 1; m <<= 1){
			LL w0 = power(inv ? power(G, mod - 2) : G, (mod - 1) / m >> 1);
			for(int j = 0; j < n; j += m << 1)
				for(LL k = 0, w = 1, tmp; k < m; k += 1, mul(w, w0)){
					tmp = a[j + k + m];
					a[j + k + m] = a[j + k];
					mul(tmp, w);
					add(a[j + k], tmp);
					sub(a[j + k + m], tmp);
				}
		}
		if(inv) for(int i = 0, n_ = power(n, mod - 2); i < n; i += 1) mul(a[i], n_);
	}
	void IDFT(P& v){
		DFT(v, true);
	}
	P operator * (const P& a, const P& b){
		int n = a.size(), m = b.size(), k = 1;
		while(k < n + m - 1) k <<= 1;
		P A(a);
		A.resize(k);
		DFT(A);
		if(&a == &b) for(int i = 0; i < k; i += 1) mul(A[i], A[i]);
		else{
			P B(b);
			B.resize(k);
			DFT(B);
			for(int i = 0; i < k; i += 1) mul(A[i], B[i]);
		}
		IDFT(A);
		A.resize(n + m - 1);
		return A;
	}
	P DCNTT(vector<P>& v, int L, int R){
		if(L == R) return v[L];
		P A = DCNTT(v, L, (L + R) >> 1), B = DCNTT(v, ((L + R) >> 1) + 1, R);
		return A * B;
	}
	P DCNTT(vector<P>& v){
		return DCNTT(v, 0, v.size() - 1);
	}
}
LL A[maxn], B[maxn];
using namespace NTT;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int N, K, Q;
	cin >> N >> K;
	for(int i = 1; i <= N; i += 1) cin >> A[i];
	cin >> Q;
	for(int i = 1; i <= Q; i += 1){
		LL t, q;
		cin >> t >> q;
		add(q, 0);
		if(t == 1){
			LL x, d;
			cin >> x >> d;
			add(d, 0);
			for(int i = 1; i <= N; i += 1) B[i] = q;
			for(int i = 1; i <= N; i += 1) sub(B[i], i == x ? d : A[i]);
		}
		else{
			LL L, R, d;
			cin >> L >> R >> d;
			add(d, 0);
			for(int i = 1; i <= N; i += 1) B[i] = q;
			for(int i = 1; i <= N; i += 1){
				sub(B[i], A[i]);
				if(i >= L and i <= R) sub(B[i], d);
			}
		}
		vector<P> v;
		for(int i = 1; i <= N; i += 1) v.push_back({1, B[i]});
		P res = DCNTT(v);
		cout << res[K] << "\n";
	}
	return 0;
}