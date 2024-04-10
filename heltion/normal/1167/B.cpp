//Author: Heltion
//Date: 2019-05-14
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void maxi(T &a, const T &b){if(b > a) a = b;}
template<typename T>void mini(T &a, const T &b){if(b < a) a = b;}
template<typename T>void no(const T &a){cout << a; exit(0);}
int a[6] ={4, 8, 15, 16, 23, 42}, b[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << "? 1 2" << endl;
	cin >> b[0];
	cout << "? 2 3" << endl;
	cin >> b[1];
	cout << "? 3 4" << endl;
	cin >> b[2];
	cout << "? 4 5" << endl;
	cin >> b[3];
	while(true){
		int x = rand() % 6, y = rand() % 6;
		swap(a[x], a[y]);
		bool ok = true;
		for(int i = 0; i < 4; i += 1) ok &= a[i] * a[i + 1] == b[i];
		if(ok){
			cout << "! ";
			for(int i = 0; i < 6; i += 1) cout << a[i] << " ";
			cout << endl;
			return 0;
		}
	}
	return 0;
}