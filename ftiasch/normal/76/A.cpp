#include <stdio.h>
#include <stdlib.h>

const int N = 200;
const int M = 50000;
const long long INF = 2000000000000000000LL;

int n, m, per_au, per_ag, x[M], y[M], au[M], ag[M], od[M], te[N], pa[N];

int compare_au(const void *a, const void *b){
	return au[*(int *)a] - au[*(int *)b];
}

int compare_ag(const void *a, const void *b){
	return ag[*(int *)a] - ag[*(int *)b];
}

int find(int x){
	if(pa[x] != x)
		pa[x] = find(pa[x]);
	return pa[x];
}

int main(){
	scanf("%d%d%d%d", &n, &m, &per_au, &per_ag);
	for(int i = 0; i != m; ++ i)
		scanf("%d%d%d%d", x + i, y + i, au + i, ag + i);
	for(int i = 0; i != m; ++ i)
		od[i] = i;
	qsort(od, m, sizeof(int), compare_au);

	long long ans = INF;
	int size = 0;
	for(int i = 0; i != m; ++ i){
		te[size ++] = od[i];
		qsort(te, size, sizeof(int), compare_ag);
		for(int j = 0; j != n; ++ j)
			pa[j] = j;
		int non = -1;
		for(int j = 0; j != size; ++ j){
			int a = x[te[j]] - 1;
			int b = y[te[j]] - 1;
			if(find(a) != find(b))
				pa[find(a)] = find(b);
			else
				non = j;
		}
		if(non != -1){
			for(int j = non + 1; j != size; ++ j)
				te[j - 1] = te[j];
			size -= 1;
		}
		if(size == n - 1){
			long long tmp = (long long)per_au * au[od[i]] + (long long)per_ag * ag[te[n - 2]];
			if(tmp < ans)
				ans = tmp;
		}
	}
	if(ans == INF)
		ans = -1;
//	printf("%lld\n", ans);
	printf("%I64d\n", ans);
	return 0;
}