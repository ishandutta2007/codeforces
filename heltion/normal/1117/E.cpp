#include<bits/stdc++.h>
using namespace std;
#define maxn 40000
char s[3][maxn];
char t[3][maxn];
char x[maxn];
int p[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin >> x;
	int n = strlen(x);
	for(int i = 0; i < n; i += 1){
		s[0][i] = i % 26 + 'a';
		s[1][i] = i / 26 % 26 + 'a';
		s[2][i] = i / 26 / 26 + 'a';
	}
	for(int i = 0; i < 3; i += 1){
		cout << "? " << s[i] << endl;
		cin >> t[i];
	}
	for(int i = 0; i < n; i += 1){
		int r = (t[0][i] - 'a') + (t[1][i] - 'a') * 26 + (t[2][i] - 'a') * 26 * 26;
		p[r] = i;
	}
	cout << "! "; 
	for(int i = 0; i < n; i += 1) cout << x[p[i]];
	cout << endl;
}