#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

map <string, int> m;
int times[10], sum[10], win[10], lose[10];
int A, B;
string names[10];

bool cmp(int a, int b){
	if (sum[a] != sum[b]) return sum[a] > sum[b];
	if (win[a] - lose[a] != win[b] - lose[b]) return win[a] - lose[a] > win[b] - lose[b];
	if (win[a] != win[b]) return win[a] > win[b];
	return names[a] < names[b];
}

int check(int x, int y){
	sum[A] += (x > y) ? 3 : (x == y) ? 1 : 0;
	sum[B] += (x < y) ? 3 : (x == y) ? 1 : 0;
	win[A] += x, lose[A] += y;
	win[B] += y, lose[B] += x;
	vector <int> v;
	for (int i = 1; i <= 4; i++){
		v.push_back(i);
	}
	sort(v.begin(), v.end(), cmp);
//	for (int i = 0; i < 4; i++){
//		cout << v[i] << " ";
//	}
//	cout << endl << endl;
	sum[A] -= (x > y) ? 3 : (x == y) ? 1 : 0;
	sum[B] -= (x < y) ? 3 : (x == y) ? 1 : 0;
	win[A] -= x, lose[A] -= y;
	win[B] -= y, lose[B] -= x;
	return v[0] == 2 || v[1] == 2;
}

pair <int, int> MIN(pair <int, int> a, pair <int, int> b){
	if (b.fi <= b.se) return a;
	if (a.fi == -1) return b;
	if (a.fi - a.se != b.fi - b.se) return (a.fi - a.se < b.fi - b.se ? a : b);
	return (a.se < b.se ? a : b);
}

int tot = 1;

int Find(string s){
	if (m.count(s)) return m[s];
	if (tot == 2) tot++;
	tot++;
	names[tot - 1] = s;
	return m[s] = tot - 1;
}

int main(){
	m["BERLAND"] = 2, names[2] = "BERLAND";
	for (int i = 0; i < 5; i++){
		string s1, s2;
		cin >> s1 >> s2;
		int a = Find(s1), b = Find(s2);
		times[a]++, times[b]++;
		int x, y;
		scanf("%d:%d", &x, &y);
		sum[a] += (x > y) ? 3 : (x == y) ? 1 : 0;
		sum[b] += (x < y) ? 3 : (x == y) ? 1 : 0;
		win[a] += x, lose[a] += y;
		win[b] += y, lose[b] += x;
	}
	for (int i = 1; i <= 4; i++){
		if (times[i] != 3){
			if (i != 2) B = i;
			else A = i;
		}
	}
	vector <int> order;
	for (int i = 1; i <= 4; i++){
		order.push_back(i);
	}
	sort(order.begin(), order.end(), cmp);
//	for (int i = 0; i <= 3; i++){
//		cout << order[i] << " " << sum[order[i]] << "  ";
//	}
//	cout << endl;
	int pos;
	for (int i = 0; i <= 3; i++){
		if (order[i] == 2) pos = i;
	}
//	cout << "pos:" << pos << endl;
	pair <int, int> ans(-1, -1);
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (check(i, j)){
				ans = MIN(ans, make_pair(i, j));
			}
		}
	}
	if (ans.fi == -1) cout << "IMPOSSIBLE" << endl;
	else cout << ans.fi << ":" << ans.se << endl;
	return 0;
}