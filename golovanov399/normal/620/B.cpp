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

// char ok[10][7] = {{1, 1, 1, 0, 1, 1, 1},
// {0, 0, 1, 0, 0, 1, 0},
// {1, 0, 1, 1, 1, 0, 1},
// {1, 0, 1, 1, 0, 1, 1},
// {0, 1, 1, 1, 0, 1, 0},
// {1, 1, 0, 1, 0, 1, 1},
// {1, 1, 0, 1, 1, 1, 1},
// {1, 0, 1, 0, 0, 1, 0},
// {1, 1, 1, 1, 1, 1, 1},
// {1, 1, 1, 1, 0, 1, 1}};

int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int qw(int x){
	int res = 0;
	while (x){
		res += cnt[x % 10];
		x /= 10;
	}
	return res;
}

int main(){

	int a = nxt(), b = nxt();
	int ans = 0;
	for (int i = a; i <= b; i++)
		ans += qw(i);
	printf("%d\n", ans);

	return 0;
}