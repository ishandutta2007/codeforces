#include <bits/stdc++.h>
using namespace std;

const int maxN = 15000005;

int lpf[maxN], f[maxN];

void init(){
	memset(f, 0, sizeof(f));
	memset(lpf, -1, sizeof(lpf));
	for(int i = 2; i*i < maxN; i++){
		if(lpf[i] == -1){
			for(int j = i*i; j < maxN; j += i){
				if(lpf[j] == -1)lpf[j] = i;
			}
		}
	}
	for(int i = 2; i < maxN; i++){
		if(lpf[i] == -1)lpf[i] = i;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int g = 0;
	for(int i = 0; i < n; i++){
		g = __gcd(g, a[i]);
	}
	for(int i = 0; i < n; i++){
		int x = a[i]/g;
		while(x > 1){
			int y = lpf[x];
			while(x%y == 0){
				x /= y;
			}
			f[y]++;
		}
	}
	int val = *max_element(f, f + maxN);
	if(val == 0){
		cout << -1 << '\n';
	}else{
		cout << n - val << '\n';
	}

	return 0;
}