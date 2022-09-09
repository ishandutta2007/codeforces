//Author: Heltion
//Date: 07-24-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int q;
	for(cin >> q; q; q -= 1){
		int b, w, tag = 0;
		cin >> b >> w;
		if(w > b){
			swap(b, w);
			tag = 1;
		}
		if(w * 3 + 1 < b) cout << "NO\n";
		else{
			cout << "YES\n";
			for(int i = 1; i <= 2 * w; i += 1) cout << 2 + tag << " " << i << "\n";
			b -= w;
			for(int i = 2; i <= 2 * w and b; i += 2, b -= 1) cout << 1 + tag << " " << i << "\n";
			for(int i = 2; i <= 2 * w and b; i += 2, b -= 1) cout << 3 + tag << " " << i << "\n";
			if(b) cout << 2 + tag << " " << 2 * w + 1 << "\n";
		}
	}
	return 0;
}