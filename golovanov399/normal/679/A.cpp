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

string ask(int n){
	cout << n << endl;
	string s;
	cin >> s;
	return s;
}

void answer(string s){
	cout << s << endl;
	exit(0);
}

bool is_prime(int x){
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main(){

	vector<int> a(4);
	vector<int> p({2, 3, 5, 7});
	for (int i = 0; i < 4; i++){
		a[i] = (ask(p[i]) == "yes" ? 1 : 0);
	}
	if (accumulate(all(a), 0) == 0)
		answer("prime");
	else if (accumulate(all(a), 0) > 1)
		answer("composite");
	else {
		int x = 0;
		for (int i = 0; i < 4; i++)
			if (a[i])
				x = p[i];
		string s = ask(x * x);
		if (s == "yes")
			answer("composite");
		for (int i = 11; i * x <= 100; i++){
			if (is_prime(i)){
				string s = ask(i);
				if (s == "yes")
					answer("composite");
			}
		}
		answer("prime");
	}

	return 0;
}