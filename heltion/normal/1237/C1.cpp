//Author: Heltion
//Date: 10-16-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T& s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
struct P{
	int a, b, c, id;
	bool operator < (const P &B)const{
		if(a != B.a) return a < B.a;
		if(b != B.b) return b < B.b;
		return c < B.c;	
	}
}p[maxn];
map<pair<int, int>, set<P>> mpsp;
map<int, set<P>> mp;
set<P> ss;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1){
		cin >> p[i].a >> p[i].b >> p[i].c;
		p[i].id = i;
		mpsp[{p[i].a, p[i].b}].insert(p[i]);
	}
	for(auto& p : mpsp){
		auto& s = p.second;
		P x, y;
		bool res = false;
		while(not s.empty()){
			x = *s.begin();
			s.erase(x);
			if(s.empty()){
				res = true;
				break;
			}
			y = *s.begin();
			s.erase(y);
			cout << x.id << " " << y.id << "\n";
		}
		if(res) mp[x.a].insert(x);
	}
	for(auto& p : mp){
		auto& s = p.second;
		P x, y;
		bool res = false;
		while(not s.empty()){
			x = *s.begin();
			s.erase(x);
			if(s.empty()){
				res = true;
				break;
			}
			y = *s.begin();
			s.erase(y);
			cout << x.id << " " << y.id << "\n";
		}
		if(res) ss.insert(x);
	}
	P x, y;
	bool res = false;
	while(not ss.empty()){
		x = *ss.begin();
		ss.erase(x);
			if(ss.empty()){
			res = true;
			break;
		}
		y = *ss.begin();
		ss.erase(y);
		cout << x.id << " " << y.id << "\n";
	}
	return 0;
}