#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

#define eps 0.00000001

using namespace std;

int o[1000],n;
double ans;
char s[2050];

inline void go(int &x) {
	int p = 0; double tmp = 0.00;
	while ( (s[x] >= '0' && s[x] <= '9' ) || s[x] == '.') {
		if (s[x] == '.') 
			p = x;
		else
			tmp = tmp * 10 + s[x] - '0';
		x++;
	}
	x--;
	if (p && x - p == 2) tmp = tmp / 100.00;
	ans += tmp;
}

int main()
{
	scanf("%s",s+1); n =strlen(s+1);
	
	for (int i=1;i<=n;i++)
		if (s[i] >= '0' && s[i] <= '9')	go(i); 
	
	double point = ans - floor(ans) + eps;
	int k = ans , l = 0;
	while (k) {
		o[++l] = k % 10;
		k /= 10;
	}
	
	for (int i=l;i>=1;i--) {
		if (i%3 == 0 && i!=l) printf(".");
		printf("%d",o[i]);
	}
	
	if (!l) printf("0");
	
	if (point > eps) {
		point = (point+eps) * 100;
		int t = point;
		if (t >= 10) 
			printf(".%d\n",t);
		else
			printf(".0%d\n",t);
	} else {
		printf("\n");
	}
	
	return 0;
}