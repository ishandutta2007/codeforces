#include <bits/stdc++.h>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, l, k;
	cin >> n >> l >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	vector<int> freq(26, 0);
	for(char c : s) freq[c-'a']++;
	vector<string> a(n, string(l, '.'));
 
	int v = 0;
	int c = 0;
	for(int j = 0; j < l; j++){
 		for(int i = v; i < k; i++){
			while(freq[c] == 0) c++;
			a[i][j] = 'a' + c;
			freq[c]--;
		}
		while(a[v][j] != a[k-1][j]) v++;
	}
 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < l; j++){
			if(a[i][j] == '.'){
				while(freq[c] == 0) c++;
				a[i][j] = 'a' + c;
				freq[c]--;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << '\n';
	}
}