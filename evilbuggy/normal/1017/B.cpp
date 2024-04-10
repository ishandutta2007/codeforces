#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string a;
	cin >> a;
	string b;
	cin >> b;
	vector<long long> cnt(4);
	for(int i = 0; i < n; i++){
		int val = ((a[i] - '0') << 1) | (b[i] - '0');
		cnt[val]++;
	}
	long long answer = 0;
	for(int a1 : {0, 1}){
		for(int a2 : {0, 1}){
			for(int b1 : {0, 1}){
				for(int b2 : {0, 1}){
					int v1 = a1|b1;
					int v2 = a2|b2;
					int w1 = a2|b1;
					int w2 = a1|b2;
					if(v1 != w1 || v2 != w2){
						answer += cnt[(a1 << 1)|b1]*cnt[(a2 << 1)|b2];
					}
				}
			}
		}
	}
	answer >>= 1;
	cout << answer << '\n';

	return 0;
}