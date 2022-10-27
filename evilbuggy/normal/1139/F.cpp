#include <bits/stdc++.h>
using namespace std;

struct Query{
	int type, ind, mul;
	int x, y, z;
	Query(){}
	Query(int it, int ii, int im, int ix, int iy, int iz){
		type = it; ind = ii; mul = im; x = ix; y = iy; z = iz;
	}
};

const int N = 100005;
const int M = 300005;

Query qur[M];
int sz, timer, p[N], s[N], b[N], x[N], y[N], ans[N], f[M], vec[M], when[M];

inline void update(int i, int x){
	while(i <= sz){
		if(when[i] < timer){
			when[i] = timer;
			f[i] = 0;
		}
		f[i] += x;
		i += i&(-i);
	}
}

inline int query(int i){
	int ret = 0;
	while(i){
		if(when[i] < timer){
			when[i] = timer;
			f[i] = 0;
		}
		ret += f[i];
		i &= (i - 1);
	}
	return ret;
}

void compute(int l, int r){
	if(l == r)return;
	
	int m = (l + r)/2;
	compute(l, m);
	compute(m + 1, r);

	++timer;
	vector<Query> res;
	int i = l, j = m + 1;
	while(i <= m && j <= r){
		if(qur[i].y <= qur[j].y){
			update(qur[i].z, qur[i].mul);
			res.push_back(qur[i]);
			i++;
		}else{
			ans[qur[j].ind] += query(qur[j].z);
			res.push_back(qur[j]);
			j++;
		}
	}
	while(i <= m){
		res.push_back(qur[i]);
		i++;
	}
	while(j <= r){
		ans[qur[j].ind] += query(qur[j].z);
		res.push_back(qur[j]);
		j++;
	}
	for(int i = l; i <= r; i++){
		qur[i] = res[i - l];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> s[i]; s[i]++;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> y[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> x[i];
	}
	sz = 0;
	for(int i = 1; i <= m; i++){
		vec[sz] = y[i]; sz++;
		vec[sz] = y[i] + x[i]; sz++;
		vec[sz] = y[i] - x[i]; sz++;
	}
	sort(vec, vec + sz);
	sz = unique(vec, vec + sz) - vec;
	
	int qsz = 0;
	for(int i = 1; i <= n; i++){
		int xc = lower_bound(vec, vec + sz, p[i] + b[i]) - vec;
		int yc = lower_bound(vec, vec + sz, p[i] - b[i]) - vec;
		int zc1 = lower_bound(vec, vec + sz, p[i]) - vec;
		int zc2 = lower_bound(vec, vec + sz, s[i]) - vec;
		qur[qsz] = Query(0, 0, +1, xc + 1, yc + 1, zc1 + 1); ++qsz;
		qur[qsz] = Query(0, 0, -1, xc + 1, yc + 1, zc2 + 1); ++qsz;
	}
	for(int i = 1; i <= m; i++){
		int xc = lower_bound(vec, vec + sz, y[i] + x[i]) - vec;
		int yc = lower_bound(vec, vec + sz, y[i] - x[i]) - vec;
		int zc = lower_bound(vec, vec + sz, y[i]) - vec;
		qur[qsz] = Query(1, i, 0, xc + 1, yc + 1, zc + 1); ++qsz;
	}
	sort(qur, qur + qsz, [&](Query a, Query b){
		if(a.x == b.x)return a.type < b.type;
		return a.x < b.x;
	});
	timer = 0;
	memset(ans, 0, sizeof(ans));
	memset(when, 0, sizeof(when));
	compute(0, qsz - 1);
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

	return 0;
}