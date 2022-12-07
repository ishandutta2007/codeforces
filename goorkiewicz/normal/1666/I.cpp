#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define f first
#define s second
#define pb push_back

int dig(int y, int x){
	printf("DIG %d %d\n", y, x);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int scan(int y, int x){
	printf("SCAN %d %d\n", y, x);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}


void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int Q1 = scan(1, 1);
	int Q2 = scan(n, 1);

	Q1 += 4;
	Q2 += 2 - 2 * n;

	assert((Q1 - Q2) % 2 == 0);
	assert((Q1 + Q2) % 2 == 0);
	
	int apb = (Q1 - Q2) / 2;
	int cpd = (Q1 + Q2) / 2;

	int y = apb / 2;
	int x = cpd / 2;
	
	int Q3 = scan(y, 1);
	int Q4 = scan(y, x);

	Q3 += 2;

	int c = (Q3 - Q4) / 2;
	int d = cpd - c;
	int a = (Q1 - Q3) / 2;
	int b = apb - a;
	
	int found = 0;

	found += dig(a, c);

	if (found == 1){
		found += dig(b, d);
	}else{
		found += dig(a, d);
		found += dig(b, c);
	}

	assert(found == 2);
}

int main()
{
	int q;
	scanf("%d", &q);
	while (q--){
		solve();
	}
	return 0;
}