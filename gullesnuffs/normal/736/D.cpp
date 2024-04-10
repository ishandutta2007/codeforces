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
typedef bitset<2000> bs;

bs vec[2005];
bool ans[2005][2005];
bs vec2[2005];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int> > input;
	rep(i,0,m){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		input.emplace_back(a, b);
		vec[a].set(b);
	}
	rep(i,0,n)
		vec2[i].set(i);
	rep(i,0,n){
		rep(j,i,n){
			if(vec[j].test(i)){
				swap(vec[i], vec[j]);
				swap(vec2[i], vec2[j]);
				break;
			}
		}
		rep(j,i+1,n){
			if(vec[j].test(i)){
				vec[j] ^= vec[i];
				vec2[j] ^= vec2[i];
			}
		}
	}
	rrep(i,n,0){
		rep(j,0,i){
			if(vec[j].test(i)){
				vec[j] ^= vec[i];
				vec2[j] ^= vec2[i];
			}
		}
	}
	/*rep(i,0,n){
		bs b;
		b.reset();
		b.set(i);
		rep(j,0,n){
			int s=((b&vec[j]).count())%2;
			ans[i][j]=!s;
		}
	}*/
	for(auto p : input){
		puts(vec2[p.second].test(p.first)?"NO":"YES");
	}
}