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

void panic(){
	puts("-1");
	exit(0);
}

int main(){

	int n = nxt(), d = nxt(), h = nxt();
	if (h + h < d){
		panic();
	}
	if (h > d){
		panic();
	}

	if (d == 1 && n > 2){
		panic();
	}

	for (int i = 0; i < h; i++){
		printf("%d %d\n", i + 1, i + 2);
	}
	for (int i = 0; i < d - h - 1; i++){
		printf("%d %d\n", h + i + 2, h + i + 3);
	}
	if (h < d)
		printf("%d %d\n", 1, h + 2);
	for (int i = 0; i < n - d - 1; i++){
		printf("%d %d\n", h, n - i);
	}

	return 0;
}