//Author: Heltion
//Date: 2019-05-17
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
constexpr int maxn = 60;
LL r[maxn], p[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int q;
	for(cin >> q; q; q -= 1){
		LL a, b, m;
		cin >> a >> b >> m;
		if(a == b){
			cout << "1 " << a << "\n";
			continue;
		}
		LL M = m;
		bool ok = false;
		for(int k = 2; (a << (k - 2)) <= b and not ok; k += 1){
			LL x = b - (a << (k - 2));
			if(x >= (1LL << (k - 2)) and (x + M - 1) / M <= (1LL << (k - 2))){
				for(int i = 2; i < k; i += 1){
					r[i] = min((x - (1LL << (k - i - 1))) >> (k - i - 1), M);
					x -= r[i] << (k - i - 1);
				}
				if(1 <= x and x <= M){
					r[k] = x;
					p[1] = a;
					for(int i = 2; i <= k; i += 1){
						p[i] = r[i];
						for(int j = 1; j < i; j += 1) p[i] += p[j];
					}
					cout << k << " ";
					for(int i = 1; i <= k; i += 1) cout << p[i] << " ";
					cout << "\n";
					ok = true;
				}
			}
		}
		if(not ok) cout << "-1\n";
		cout << endl;
	}
	return 0;
}
//a
//a + r2
//2 * a + r2 + r3
//4 * a + 2 * r2 + r3 + r4