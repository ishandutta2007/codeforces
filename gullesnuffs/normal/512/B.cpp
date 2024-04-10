#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

map<int, int> S;

int gcd(int x, int y){
	return x?gcd(y%x, x):y;
}

int L[305], C[305];

int main(){
	int n;
	scanf("%d", &n);
	rep(i,0,n){
		scanf("%d", L+i);
	}
	rep(i,0,n){
		scanf("%d", C+i);
	}
	rep(i,0,n){
		int l, c;
		l=L[i];
		c=C[i];
		if(S.find(l) == S.end() || S[l] > c)
			S[l]=c;
	}
	while(!S.empty()){
		auto it=S.end();
		--it;
		if(it->first == 1){
			printf("%d\n", it->second);
			return 0;
		}
		vector<pair<int, int> > add;
		for(auto it2=S.begin(); it2 != S.end(); ++it2){
			int g=gcd(it->first, it2->first);
			add.push_back(make_pair(g, it->second+it2->second));
		}
		for(int i=0; i < add.size(); ++i){
			if(S.find(add[i].first) == S.end() || S[add[i].first] > add[i].second)
				S[add[i].first]=add[i].second;
		}
		it=S.end();
		--it;
		S.erase(it);
	}
	puts("-1");
}