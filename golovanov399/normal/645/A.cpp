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

	string s1, s2, t1, t2;
	cin >> s1 >> s2 >> t1 >> t2;
	reverse(all(s2));
	reverse(all(t2));
	s1 += s2;
	t1 += t2;
	string s = "", t = "";
	for (int i = 0; i < 4; i++)
		if (s1[i] != 'X')
			s += s1[i];
	for (int i = 0; i < 4; i++)
		if (t1[i] != 'X')
			t += t1[i];

	int i = t.find(s[0]);
	t = t.substr(i) + t.substr(0, i);
	if (s == t){
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}