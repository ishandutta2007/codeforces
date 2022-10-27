#include <bits/stdc++.h>
using namespace std;

inline array<long long, 2> operator+(array<long long, 2> a, array<long long, 2> b){
	return array<long long, 2> ({a[0] + b[0], a[1] + b[1]});
}

inline array<long long, 2> operator-(array<long long, 2> a, array<long long, 2> b){
	return array<long long, 2> ({a[0] - b[0], a[1] - b[1]});
}

inline long long cross(array<long long, 2> a, array<long long, 2> b){
	return a[0]*b[1] - a[1]*b[0];
}

inline long long dot(array<long long, 2> a, array<long long, 2> b){
	return a[0]*b[0] + a[1]*b[1];
}

inline long long dist2(array<long long, 2> a, array<long long, 2> b){
	return (a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]);
}

vector<array<long long, 2> > convexHull(vector<array<long long, 2> > a){
	int n = (int)a.size();
	sort(a.begin(), a.end());
	vector<array<long long, 2> > up, dw;
	for(int i = 0; i < n; i++){
		int szu = (int)up.size();
		int szd = (int)dw.size();
		while(szu >= 2 && cross(up[szu - 2] - up[szu - 1], a[i] - up[szu - 1]) <= 0){
			up.pop_back(); szu--;
		}
		while(szd >= 2 && cross(dw[szd - 2] - dw[szd - 1], a[i] - dw[szd - 1]) >= 0){
			dw.pop_back(); szd--;
		}
		up.push_back(a[i]);
		dw.push_back(a[i]);
	}
	dw.pop_back();
	while(dw.size() > 1){
		up.push_back(dw.back());
		dw.pop_back();
	}
	return up;
}

vector<array<long long, 3> > get(vector<array<long long, 2> > a){
	int n = (int)a.size();
	vector<array<long long, 3> > ret;
	for(int i = 0; i < n; i++){
		int nxt = (i + n + 1)%n;
		int prv = (i + n - 1)%n;
		ret.push_back({cross(a[nxt] - a[i], a[prv] - a[i]), dot(a[nxt] - a[i], a[prv] - a[i]), dist2(a[i], a[nxt])});
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<array<long long, 2> > a(n);
	vector<array<long long, 2> > b(m);
	for(int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1];
	}
	for(int j = 0; j < m; j++){
		cin >> b[j][0] >> b[j][1];
	}
	a = convexHull(a);
	b = convexHull(b);
	if(a.size() != b.size()){
		cout << "NO" << '\n';
		exit(0);
	}
	if(a.size() == 2){
		if(dist2(a[0], a[1]) == dist2(b[0], b[1])){
			cout << "YES" << '\n';
		}else{
			cout << "NO" << '\n';
		}
		exit(0);
	}
	vector<array<long long, 3> > va = get(a);
	vector<array<long long, 3> > vb = get(b);
	for(int i = 0; i < n; i++){
		va.push_back(va[i]);
	}
	n = (int)a.size();
	m = (int)b.size();
	vector<int> f(m);
	int i = 1, j = 0;
	while(i < m){
		if(vb[i] == vb[j]){
			f[i] = j + 1;
			++i; ++j;
		}else if(j){
			j = f[j - 1];
		}else{
			++i;
		}
	}
	i = 0, j = 0;
	while(i < n + n){
		if(j == m){
			cout << "YES" << '\n';
			exit(0);
		}
		if(va[i] == vb[j]){
			++i; ++j;
		}else if(j){
			j = f[j - 1];
		}else{
			++i;
		}
	}
	if(j == m){
		cout << "YES" << '\n';
	}else{
		cout << "NO" << '\n';
	}

	return 0;
}