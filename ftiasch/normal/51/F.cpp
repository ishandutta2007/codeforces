#include <cstdio>
#include <cstring>
#include <climits>

const int N = 2000 + 1;
const int M = 100000 * 2 + 2;

int n, m, a[M], b[M], answer, time, stamp[N], lowest[N], top, stack[N], bcc, number[N], degree[N];
bool visit[M];

void update(int &x, int a){
	if(a < x)
		x = a;
}

struct graph{
	int size, first[N], to[M], next[M];
	
	void init(){
		size = 1;
		memset(first, 0, sizeof(first));
	}

	void add_edge(int u, int v){
		size += 1;
		to[size] = v;
		next[size] = first[u];
		first[u] = size;
	}

	void contract(int x){
		stamp[x] = lowest[x] = ++ time;
		stack[++ top] = x;
		for(int iter = first[x]; iter; iter = next[iter]){
			if(visit[iter >> 1])
				continue;
			visit[iter >> 1] = true;
			int y = to[iter];
			if(stamp[y])
				update(lowest[x], stamp[y]);
			else{
				contract(y);
				update(lowest[x], lowest[y]);
				if(stamp[y] == lowest[y]){
					bcc += 1;
					while(1){
						number[stack[top --]] = bcc;
						if(stack[top + 1] == y)
							break;
						answer += 1;
					}
				}
			}

		}
	}

	void after(){
		bcc += 1;
		while(top){
			number[stack[top --]] = bcc;
			answer += 1;
		}
		answer -= 1;
	}

	void find(int &o, int &od, int p, int x, int d){
		if(degree[x] == 1)
			return;
		visit[x] = true;
		if(d > od)
			o = x, od = d;
		for(int iter = first[x]; iter; iter = next[iter]){
			int y = to[iter];
			if(y != p)
				find(o, od, x, y, d + 1);
		}
	}
}g, t;

int main(){
	scanf("%d%d", &n, &m);
	g.init();
	for(int i = 1; i <= m; ++ i){
		scanf("%d%d", a + i, b + i);
		g.add_edge(a[i], b[i]);
		g.add_edge(b[i], a[i]);
	}
	answer = -1;
	time = top = bcc = 0;
	memset(stamp, 0, sizeof(stamp));
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= n; ++ i)
		if(!stamp[i]){
			answer += 1;
			g.contract(i);
			g.after();
		}
	memset(degree, 0, sizeof(degree));
	t.init();
	for(int i = 1; i <= m; ++ i)
		if(number[a[i]] != number[b[i]]){
			degree[number[a[i]]] += 1;
			degree[number[b[i]]] += 1;
			t.add_edge(number[a[i]], number[b[i]]);
			t.add_edge(number[b[i]], number[a[i]]);
		}
	for(int i = 1; i <= bcc; ++ i)
		answer += degree[i] > 1;
	memset(visit, 0, sizeof(visit));
	for(int i = 1; i <= bcc; ++ i)
		if(!visit[i] && degree[i] > 1){
			int tmp, tmp_dis;
			tmp_dis = INT_MIN;
			t.find(tmp, tmp_dis, 0, i, 1);
			tmp_dis = INT_MIN;
			t.find(tmp, tmp_dis, 0, tmp, 1);
			answer -= tmp_dis;
		}
	printf("%d\n", answer);
	return 0;
}