//This stick is very steki!
#include <iostream>
#include <vector>
using namespace std;
#define mod 10009
struct uf{
	int par[55],ran[55],sz[55];
	void init(){
		for(int i=0;i<55;i++) par[i] = i,sz[i] = 1;
	}
	int find(int x){
		if(x == par[x]) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int a,int b){
		a = find(a);
		b = find(b);
		if(a != b){
			if(ran[a] < ran[b]){
				par[a] = b;
				sz[b] += sz[a];
			}
			else{
				par[b] = a;
				sz[a] += sz[b];
				if(ran[a] == ran[b]) ran[a]++;
			}
		}
	}
	bool same(int a,int b){
		return find(a) == find(b);
	}
	int SIZE(int x){
		return sz[find(x)];
	}
}kaede;
int n;
vector<pair<int,int> >takagaki,takagaki2;
int nxt=1,r[55],num[55];


int f[23], I[(1<<23)];
int mod_pow(int a, int k){
	int ret = 1,cur = a;
	for(int i=0;i<5;i++){
		if(((k>>i)&1)) ret = ret * cur % mod;
		cur = cur * cur % mod;
	}
	return ret;
}

bool can(int k) {
    int res = 0;
    for(int S=0;S<(1<<nxt);++S) {
        if(__builtin_popcount(S)%2 == 1) res -= mod_pow(I[S], k);
        else res += mod_pow(I[S],k);
        res %= mod;
    }
    return (res%mod+mod)%mod;
}

int calc() {
    I[0] = 1;
    for(int i=0;i<takagaki2.size();i++){
    	int a = takagaki2[i].first,b = takagaki2[i].second;
    	a--; b--;
    	f[a] |= (1<<b);
    	f[b] |= (1<<a);
    }
    for(int i=0;i<nxt;i++) f[i] |= (1<<i);
    for(int S=1;S<(1<<nxt);++S) {
        int v = 0;
        while(!(S&(1<<v))) v++;
        I[S] = I[S-(1<<v)] + I[S&(~f[v])];
        I[S] %= mod;
    }
    int lb = -1, ub = nxt, mid;
    while(ub-lb>1){
        mid = (lb+ub)/2;
        if(can(mid)) ub = mid;
        else lb = mid;
    }
    return ub;
}

int main() {
	cin >> n;
	kaede.init();
	for(int i=0;i<n;i++){
		string s; cin >> s;
		for(int j=0;j<n;j++){
			if(s[j] == 'A') kaede.unite(i,j);
			else if(s[j] == 'X') takagaki.push_back(pair<int,int>(i,j));
		}
	}
	for(int i=0;i<takagaki.size();i++){
		if(kaede.same(takagaki[i].first,takagaki[i].second)){
			puts("-1");
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		if(kaede.find(i) == i && kaede.SIZE(i) >= 2){
			r[i] = nxt++;
		}
	}
	for(int i=0;i<takagaki.size();i++){
		int u = kaede.find(takagaki[i].first);
		int v = kaede.find(takagaki[i].second);
		if(r[u] && r[v]){
			takagaki2.push_back(pair<int,int>(r[u],r[v]));
		}
	}
	nxt--;
	int kaede_is_my_wife = calc();
	cout << n-1+kaede_is_my_wife << endl;
}