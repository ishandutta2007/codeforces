//Author: Heltion
//Date: 10-16-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 1200000;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	set<int> s;
	int a = 1, b = 2;
	int x = 0;
	while(a <= maxn or b <= maxn){
		//cout << a << " " << b << endl;
		s.insert(a);
		s.insert(b);
		if(x == 0){
			a = b * 2;
			b = a + 1;
		}
		else{
			b = b * 2;
			a = b - 1;
		}
		x ^= 1;
	}
	int n;
	cin >> n;
	cout << s.count(n);
	return 0;
}