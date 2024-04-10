// Codeforces Beta Round #64
// Problem C -- Lucky Tickets
#include <map>
#include <cstdio>
#include <utility>

using namespace std;

const int N = 100001;
typedef pair<int, int> fraction;

int gcd(int a, int b){
	return b? gcd(b, a % b): a;
}

fraction make(int a, int b){
	int d = gcd(a, b);
	return fraction(a / d, b / d);
}

int rev(int x){
	int y = 0;
	while(x)
		y = y * 10 + x % 10, x /= 10;
	return y;
}

long long mul(int x, int y){
	return (long long)(x) * (long long)(y);
}

int max_x, max_y, w;
fraction ind_x[N], ind_y[N];
map<fraction, int> cnt_x, cnt_y;

int main(){
	scanf("%d%d%d", &max_x, &max_y, &w);
	for(int i = 1; i <= max_x; ++ i)
		ind_x[i] = make(i, rev(i));
	for(int j = 1; j <= max_y; ++ j)
		ind_y[j] = make(rev(j), j);
	cnt_x.clear();
	for(int i = 1; i <= max_x; ++ i)
		cnt_x[ind_x[i]] += 1;
	int i = max_x, ans_x = max_x + 1, ans_y = max_y + 1;
	cnt_y.clear();
	for(int j = 1; j <= max_y; ++ j){
		w -= cnt_x[ind_y[j]];
		cnt_y[ind_y[j]] += 1;
		if(w <= 0){
			for(;w + cnt_y[ind_x[i]] <= 0; -- i){
				w += cnt_y[ind_x[i]];
				cnt_x[ind_x[i]] -= 1;
			}
			if(mul(i, j) < mul(ans_x, ans_y))
				ans_x = i, ans_y = j;
		}
	}
	if(ans_x <= max_x && ans_y <= max_y)
		printf("%d %d\n", ans_x, ans_y);
	else
		printf("-1\n");
	return 0;
}