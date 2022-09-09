//Author: Heltion
//Date: 08-12-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 10;
bitset<maxn> b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(char c : s){
		if(c == 'R') for(int i = 0; i < 10; i += 1) if(not b.test(i)){
			b.set(i);
			break;
		}
		if(c == 'L') for(int i = 9; ~i; i -= 1) if(not b.test(i)){
			b.set(i);
			break;
		}
		if(c >= '0' and c <= '9') b.reset('9' - c);
	}
	cout << b;
	return 0;
}