#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2e5+5, mv = 2e5+5, nove = 1e9, inf = 0x3f3f3f3f;
const ll mod = 1e9+7;


string cop;
int len;

int solve(char a, char b) {
	if(len  == 1) return inf;
	string n = cop;
	int ans = 0;
	bool achou = false;
	//cout << len << ' ' << n << endl;
	for(int i = len - 1; i >= 0 && !achou; i--) {
	//	cout << "Comecando Trocas hihi " << endl;
		if(n[i] == b) {
			if(i == 0) {
				int k = 1;
				while(k < len - 1 && n[k] == '0') {
					k++;
				}
				if(k >= len) return inf;
				for(int j = k; j > 1; j--) {
					ans++;
					swap(n[j], n[j-1]);
				}
			}
			for(int j = i; j < len - 1; j++) {
				ans++;
				swap(n[j], n[j+1]);
			}
			achou = true;
		}
	}
	//cout << a << ' ' << b << ' ' << n << endl;
	//cout << "Fim de trocas" << endl;
	if(!achou) return inf;
	for(int i = len - 2; i >= 0; i--) {
		if(n[i] == a) {
			if(i == 0) {
				if(len == 2) return ans;
				int k = 1;
				while(k < len - 1 && n[k] == '0') {
					k++;
				}
				//cout << k << ' ' << len - 1 << endl;
				if(k >= len - 1) return inf;
				for(int j = k; j > 1; j--) {
					ans++;
					swap(n[j], n[j-1]);
				}
				//cout << "Consertado 0 = " << n << endl;
			}
			for(int j = i; j < len - 2; j++) {
				ans++;
				swap(n[j], n[j+1]);
			}
			return ans;
		}
	}
	return inf;
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> cop;
	len = cop.size();
	int ans = min(min(solve('0', '0'), solve('2', '5')), min(solve('5', '0'), solve('7', '5')));
	if(ans == inf) ans = -1;
	cout << ans << endl;
	return 0;
}