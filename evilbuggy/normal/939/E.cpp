#include <bits/stdc++.h>
using namespace std;

deque<pair<long double, long double> > hull;

inline long double eval(pair<long double, long double> line, long double x){
	return line.first*x + line.second;
}

inline bool check(pair<long double, long double> a, pair<long double, long double> b, pair<long double, long double> c){
	long double xab = (b.second - a.second)/(a.first - b.first);
	long double xac = (c.second - a.second)/(a.first - c.first);
	return xab < xac;
}

inline void add(long double m, long double c){
	int sz = (int)hull.size();
	while(sz >= 2 && !check(hull[sz - 2], hull[sz - 1], {m, c})){
		hull.pop_back(); sz--;
	}
	hull.emplace_back(m, c);
}

int main(){
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);
	cin.tie(nullptr);

	int q, x;
	cin >> q;
	int n = 0;
	long long sum = 0;
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			cin >> x;
			add(n*1.0/(n + 1), -sum*1.0/(n + 1));
			sum += x; n++;
		}else{
			while(hull.size() > 1){
				if(eval(hull[0], x) < eval(hull[1], x)){
					hull.pop_front();
				}else{
					break;
				}
			}
			cout << eval(hull[0], x) << '\n';
		}
	}

	return 0;
}