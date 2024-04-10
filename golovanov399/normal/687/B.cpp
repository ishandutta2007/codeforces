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

const int N = 1111111;
char ok[N];

int main(){

	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		ok[nxt()] = 1;

	for (int i = 2; i * i <= k; i++){
		if (k % i == 0){
			int g = 1;
			while (k % i == 0){
				g *= i;
				k /= i;
			}
			char win = false;
			for (int j = g; j < N; j += g)
				win |= ok[j];
			if (!win){
				puts("No");
				return 0;
			}
		}
	}
	if (k > 1){
		char win = false;
		for (int j = k; j < N; j += k)
			win |= ok[j];
		if (!win){
			puts("No");
			return 0;
		}		
	}

	puts("Yes");

	return 0;
}