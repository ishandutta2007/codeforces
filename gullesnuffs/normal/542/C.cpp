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

int f[205];

int main(){
	int n;
	scanf("%d", &n);
	ll c=0, d=1;
	rep(i,0,n){
		scanf("%d", f+i);
		--f[i];
	}
	rep(i,0,n){
		int u=f[i];
		int v=f[f[i]];
		ll a=1;
		while(u != v){
			if(u == i)
				break;
			u=f[u];
			v=f[f[v]];
			++a;
		}
		int tmp=0;
		ll b=1;
		ll w=f[u];
		while(w != u){
			w=f[w];
			++b;
		}
		if(f[i] == i){
			a=0;
			b=1;
		}
		ll y;
		for(y=0; (c-a+d*y)%b || (c-a+d*y)/b < 0; ++y);
		ll y2;
		for(y2=y+1; (c-a+d*y2)%b; ++y2);
		ll cp=c+d*y;
		ll dp=d*(y2-y);
		c=cp;
		d=dp;
	}
	if(!c)
		c=1;
	cout << c << endl;
}