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

	int n = nxt();
	int x = 0;
	for (int i = 0; i < n; i++){
		if (i == 0){
			x = nxt();
			while (x % 2 == 0)
				x /= 2;
			while (x % 3 == 0)
				x /= 3;
		} else {
			int y = nxt();
			while (y % 2 == 0)
				y /= 2;
			while (y % 3 == 0)
				y /= 3;
			if (y != x){
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");

	return 0;
}