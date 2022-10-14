// Yandex Algorithm 2011 Round 2
// Problem D -- Powerful array
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200000;
const int M = 1000001;

int n, m, b, a[N], l[N], r[N], o[N], c[M];
long long cw, w[N];

bool cmp(int i, int j){
	if(l[i] / b == l[j] / b)
		return r[i] > r[j];
	return l[i] < l[j];
}

void add(int i){
	c[a[i]] += 1;
	cw += (2LL * c[a[i]] - 1) * a[i];
}

void del(int i){
	cw -= (2LL * c[a[i]] - 1) * a[i];
	c[a[i]] -= 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++ i)
		scanf("%d", a + i);
	for(int i = 0; i < m; ++ i){
		scanf("%d%d", l + i, r + i);
		l[i] -= 1;
		r[i] -= 1;
	}
	for(int i = 0; i < m; ++ i)
		o[i] = i;
	b = (int)sqrt(n);
	sort(o, o + m, cmp);
	int cl = 0;
	int cr = 0;
	cw = a[0];
	memset(c, 0, sizeof(c));
	c[a[0]] = 1;
	for(int i = 0; i < m; ++ i){
		while(cr < r[o[i]])
			add(++ cr);
		while(cl < l[o[i]])
			del(cl ++);
		while(cl > l[o[i]])
			add(-- cl);
		while(cr > r[o[i]])
			del(cr --);
		w[o[i]] = cw;
	}
	for(int i = 0; i < m; ++ i)
		printf("%I64d\n", w[i]);
	return 0;
}