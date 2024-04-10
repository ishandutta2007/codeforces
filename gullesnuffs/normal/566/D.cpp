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

set<int> S;

struct UF{
	int a[200005];

	int find(int x){
		if(a[x] == -1)return x;
		return a[x]=find(a[x]);
	}

	void join(int x, int y){
		x=find(x);
		y=find(y);
		if(x == y)return;
		a[x]=y;
	}
}uf;

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	rep(i,0,n){
		uf.a[i]=-1;
		S.insert(i);
	}
	rep(i,0,q){
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		--x;--y;
		if(type == 1){
			uf.join(x,y);
		}
		else if(type == 2){
			if(x == y)
				continue;
			uf.join(x,y);
			if(x > y)swap(x,y);
			uf.join(x,x+1);
			uf.join(y,y-1);
			auto it=S.upper_bound(x);
			while(*it < y){
				uf.join(x,*it);
				S.erase(it);
				it=S.upper_bound(x);
			}
		}
		else{
			if(uf.find(x) == uf.find(y))
				puts("YES");
			else
				puts("NO");
		}
	}
}