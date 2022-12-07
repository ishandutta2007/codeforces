#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int n, k, Q;
vector<int> a, b, c;
vector<int> diff;
int ans = 0;
int possible = 0;
vector<int> sum;
int f0 = 0;
 
vector<pair<int,int> > dupds;
vector<pair<int,int> > diffupd;
 
int mp(int p){
	int r = (n+1) / k + 1;
	int a = p % k;
	int b = p / k;
	return a * r + b;
}
 
void dupd(int p, int v){
	dupds.push_back({mp(p), v});
	diffupd.push_back({p, v});
	if(sum[p % k] == 0) f0--;
	sum[p % k] ^= v;
	if(sum[p % k] == 0) f0++;
	possible = (f0 == k);
}
 
void upd2(int p, int v){
	dupd(p-1, v);
	dupd(p, v);
}
void upd(string s, int p, int v){
	if(s == "a"){
		int da = a[p] ^ v;
		a[p] ^= da;
		upd2(p, da);
	} else if(s == "b"){
		int db = b[p] ^ v;
		b[p] ^= db;
		upd2(p, db);
	}
}
 
const int B = 600;
 
int freq[2 * B + 2][1<<14];
 
vector<string> s;
vector<int> p, v;
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k >> Q;
	a.resize(n+2, 0); b.resize(n+2, 0); c.resize(n+2, 0);
	for(int i = 0; i < n; i++) cin >> a[i+1];
	for(int i = 0; i < n; i++) cin >> b[i+1];
	diff.resize(n+1);
 
	sum.resize(k);
	for(int i = 0; i <= n; i++){
		diff[i] = a[i] ^ b[i] ^ a[i+1] ^ b[i+1];
		sum[i % k] ^= diff[i];
	}
	for(int i = 0; i < k; i++){
		if(sum[i] == 0) f0++;
	}
	s.resize(Q+1), p.resize(Q+1), v.resize(Q+1);
	s[0] = "a"; p[0] = 1; v[0] = a[1];
	for(int q = 1; q <= Q; q++){
		cin >> s[q] >> p[q] >> v[q];
	}
 
	Q++;
 
	for(int i = 0; i < 2*B + 2; i++){
		for(int j = 0; j < (1<<14); j++){
			freq[i][j] = 0;
		}
	}
 
	int SZ = n + k + 6;
	for(int a = 0; a * B < Q; a++){
		vector<int> ok;
		dupds.clear();
		diffupd.clear();
		for(int q = a*B; q < Q && q < (a+1) * B; q++){
			upd(s[q], p[q], v[q]);
			ok.push_back(possible);
		}
		vector<int> psums(SZ, 0);
		for(int i = 0; i <= n; i++){
			psums[mp(i)] = diff[i];
		}
		for(int i = 1; i < SZ; i++){
			psums[i] ^= psums[i-1];
		}
 
		set<int> cc;
		cc.insert(0);
		for(auto r : dupds){
			cc.insert(r.first);
		}
		map<int,int> l;
		vector<int> stuff;
		for(int g : cc){
			int a = l.size();
			l[g] = a;
			stuff.push_back(g);
		}
		stuff.push_back(SZ);
		int Z = stuff.size();
		vector<int> off(Z, 0);
 
		int cur = 0;
		for(int i = 0; i < SZ; i++){
			if(i == stuff[cur + 1]) cur++;
			freq[cur][psums[i]] ++;
		}
		for(int q = a*B; q < Q && q < (a+1) * B; q++){
			for(int b = 0; b < 2; b++){
				int id = (q - a * B) * 2 + b;
				int loc = l[dupds[id].first];
				int x = dupds[id].second;
				for(int i = loc; i < Z; i++){
					off[i] ^= x;
				}
			}
			int nonzero = SZ;
			for(int i = 0; i < Z; i++){
				nonzero -= freq[i][off[i]];
			}
			if(ok[q - a * B]){
				cout << nonzero << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
 
		cur = 0;
		for(int i = 0; i < SZ; i++){
			if(i == stuff[cur + 1]) cur++;
			freq[cur][psums[i]]--;
		}
 
		for(auto r : diffupd){
			diff[r.first] ^= r.second;
		}
	}
}