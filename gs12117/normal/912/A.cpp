#include<cstdio>
long long int a, b, x, y, z;
int main() {
	scanf("%lld%lld", &a, &b);
	scanf("%lld%lld%lld", &x, &y, &z);
	long long int da = x * 2 + y;
	long long int db = y + z * 3;
	da -= a;
	db -= b;
	if (da < 0)da = 0;
	if (db < 0)db = 0;
	printf("%lld\n", da + db);
	return 0;
}