#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);

	string s;
	cin >> s;
	int i = 0, n = s.length();
	while (i < n && s[i] == 'a')
		i++;
	if (i == n){
		s[i - 1] = 'z';
	} else {
		while (i < n && s[i] != 'a'){
			s[i++]--;
		}
	}

	cout << s << "\n";

	return 0;
}