//Author: Heltion
//Date: 08-07-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 2400000;
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	cin >> s;
	for(int x = 0; x < 10; x += 1){
		for(int y = 0; y < 10; y += 1){
			int b[10];
			for(int i = 0; i < 10; i += 1) b[i] = 1e9;
			for(int q = 0; q < 10; q += 1)
				for(int p = 0; p < 10; p += 1)
					if(p or q)
						b[(p * x + q * y) % 10] = min(b[(p * x + q * y) % 10], p + q - 1);
			int ans = 0;
			for(int i = 0; s[i + 1]; i += 1){
				if(b[(s[i + 1] - s[i] + 10) % 10] == (int)1e9){
					ans = -1;
					break;
				}
				ans += b[(s[i + 1] - s[i] + 10) % 10];
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
	return 0;
}