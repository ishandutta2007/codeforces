#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}
#define jeb fflush(stdout)

using namespace std;

int n, k;
map<int, int> mem;

int get_a(int x) {
	x = (x % n) + 1;
	if (mem.find(x) != mem.end()) {
		return mem[x];
	} else {
		cout << "? " << x << endl;
		jeb;
		int ans;
		cin >> ans;
		mem[x] = ans;
		return ans;
	}
}

int get_b(int u) {
	int a = get_a(u);
	int b = get_a(u+k);
	return b - a;
}


int main() {
	cin >> n;
	k = n / 2;
	int l = 0; int r = k;
	int vl = get_b(0);
	int vr = get_b(k);
	if (vl % 2 != 0) {
		cout << "! -1" << endl;
		jeb;
		return 0;
	}
	while (1) {
		if (vl == 0) {
			cout << "! " << (l+1) << endl;
			jeb;
			break;
		}
		if (vr == 0) {
			cout << "! " << (r+1) << endl;
			jeb;
			break;
		}
		int mid = (l + r) / 2;
		int vm = get_b(mid);
		if (vr == 0) {
			cout << "! " << (mid+1) << endl;
			jeb;
		}
		if (vm*1LL*vl < 0) {
			r = mid;
			vr = vm;
		} else {
			l = mid;
			vl = vm;
		}
	}
}