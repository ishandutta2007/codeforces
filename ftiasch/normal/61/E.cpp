#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 1000000;

int n, a[N];
pair<int, int> b[N];
long long c[N], f[N];

void add(int x, int a){
	for(int i = x; i <= N; i += i & -i)
		c[i - 1] += a;
}

long long sum(int x){
	long long s = 0;
	for(int i = x; i >= 1; i -= i & -i)
		s += c[i - 1];
	return s;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i != n; ++ i)
		scanf("%d", a + i),
		b[i] = make_pair(a[i], i);
	sort(b, b + n);
	for(int i = 0; i != n; ++ i)
		a[b[i].second] = n - i;
	for(int i = 0; i != n; ++ i)
		f[i] = 1;
	for(int _ = 0; _ != 2; ++ _){
		memset(c, 0, sizeof(c));
		for(int i = 0; i != n; ++ i){
			long long tmp = sum(a[i]);
			add(a[i], f[i]);
			f[i] = tmp;
		}
	}
	long long tmp = 0;
	for(int i = 0; i != n; ++ i)
		tmp += f[i];
	printf("%I64d\n", tmp);
	return 0;
}