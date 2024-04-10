#include <bits/stdc++.h>
using namespace std;

struct Line{
	long long m, c;
	Line(long long im = 0, long long ic = 0){
		m = im; c = ic;
	}
	long long operator()(long long x){
		return m*x + c;
	}
};

const int maxn = 100005;

Line uwu[maxn*30];
long long a[maxn], s[maxn];
int ptr, root[maxn], child[maxn*30][2];

int update(int v, int l, int r, Line nline){
	int u = ptr++;
	if(l == r){
		uwu[u] = uwu[v];
		if(nline(l) < uwu[u](l)){
			uwu[u] = nline;
		}
		return u;
	}
	uwu[u] = uwu[v];
	child[u][0] = child[v][0];
	child[u][1] = child[v][1];

	int m = (l + r)/2;
	if(nline(m + 1) < uwu[u](m + 1)){
		if(nline(l) < uwu[u](l)){
			swap(uwu[u], nline);
			child[u][1] = update(child[u][1], m + 1, r, nline);
		}else{
			swap(uwu[u], nline);
			child[u][0] = update(child[u][0], l, m, nline);
		}
	}else{
		if(nline(l) < uwu[u](l)){
			child[u][0] = update(child[u][0], l, m, nline);
		}else{
			child[u][1] = update(child[u][1], m + 1, r, nline);
		}
	}
	return u;
}

long long query(int v, int l, int r, int x){
	if(l == r)return uwu[v](x);
	int m = (l + r)/2;
	if(x <= m)return min(uwu[v](x), query(child[v][0], l, m, x));
	else return min(uwu[v](x), query(child[v][1], m + 1, r, x));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	s[0] = 0;
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	ptr = 1; root[0] = 0;
	memset(child, 0, sizeof(child));

	deque<int> ind;
	for(int i = 1; i <= n; i++){
		while(!ind.empty() && a[ind.back()] >= a[i]){
			ind.pop_back();
		}
		if(ind.empty()){
			root[i] = update(root[0], 0, maxn - 1, Line(-a[i], a[i]*i - s[i]));
		}else{
			root[i] = update(root[ind.back()], 0, maxn - 1, Line(-a[i], a[i]*i - s[i]));
		}
		ind.emplace_back(i);
	}
	int m; cin >> m;
	for(int k = 1; k <= m; k++){
		int i; cin >> i;
		int j; cin >> j;
		cout << s[j] + query(root[j], 0, maxn - 1, j - i) << '\n';
	}

	return 0;
}