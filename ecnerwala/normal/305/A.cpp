#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N; cin >> N;
	bool is0 = 0, is100 = 0;
	int dig0 = 0, dig1 = 0;
	int other = 0;
	for(int i = 0; i < N; i++) {
		int v; cin >> v;
		if(v == 0) is0 = true;
		else if(v == 100) is100 = true;
		else if(v < 10) dig0 = v;
		else if(!(v % 10)) dig1 = v;
		else other = v;
	}
	int count = 0;
	if(is0) count++;
	if(is100) count++;
	if(dig0) count++;
	if(dig1) count++;
	if(!dig0 && !dig1 && other) count++;
	cout << count << '\n';
	if(is0) cout << 0 << ' ';
	if(is100) cout <<  100 << ' ';
	if(dig0) cout << dig0 << ' ';
	if(dig1) cout << dig1 << ' ';
	if(!dig0 && !dig1 && other) cout << other << ' ';
	cout << '\n';
	return 0;
}