#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

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

using namespace std;




int main() {
	make(n);
	make3(a,b,c);
	makev(v,n);
	sort(all(v));

	if(a>b) swap(a,b);
	if(b>c) swap(b,c);
	if(a>b) swap(a,b);

	//faza1 musze abc
	int pos = n-1;
	if(v.back()>a+b+c) {
		printf("-1\n");
		return 0;
	}
	int ans = 0;
	while(n>=1 && v[n-1]>b+c) ans++, n--;
	if(n==0) {
		printf("%d\n", ans);
		return 0;
	}
	int ka = 0, kb = 0, kc = 0, kab = 0, kbc =0, kac = 0;
	FOR(i,0,n) if(v[i]<=a) ka++;
	FOR(i,0,n) if(v[i]<=b) kb++;
	FOR(i,0,n) if(v[i]<=c) kc++;
	FOR(i,0,n) if(v[i]<=a+b) kab++;
	FOR(i,0,n) if(v[i]<=a+c) kac++;
	FOR(i,0,n) if(v[i]<=b+c) kbc++;
	kb -= ka;
	kc -= ka+kb;
	kab -=ka+kb;
	if(a+b<c) kc -= kab;
	else kab -= kc;
	kac -= ka+kb+kc+kab;
	kbc -= ka+kb+kc+kab+kac;


	// bc + ew a
	ans += kbc;
	ka -= kbc;
	if(ka<0) ka = 0;

	// ac + ew b
	ans += kac;
	kb -= kac;
	if(kb <0) {
		ka +=kb;
		kb = 0;
		if(ka<0) ka = 0;
	}

	if(c <= a+b) {
	//	debug3(ka,kb,kc);
//		debug2(kab, ans);

		ans += kab;
		kc -= kab;
		if(kc<0) {
			kb += kc; kc = 0;
			if(kb<0) { ka +=kb; kb = 0;}
			if(ka<0) ka = 0;
		}
		int ans2 = 1e9;
		FOR(t1,0,n+1) {
			int t2 = max(0,((kc-t1)+1)/2);
			t2 = max(t2, ((kc+kb)-2*t1+1)/2);
			t2 = max(t2, (kc+kb+ka -3*t1+1)/2);
			ans2 = min(ans2, t1+t2);
		}
		printf("%d\n", ans+ans2);
	}
	else {
		int ans2 = 1e9;
		FOR(t1,0,n+1) {
			int t2 = max(0, (kc-t1));
			t2 = max(t2, kc+kab-2*t1);
			t2 = max(t2, (kb+kc+kab-2*t1+1)/2);
			t2 = max(t2, (ka+kb+kc+kab-2*t1+2)/3);
			ans2 = min(ans2, t1+t2);
		}
		printf("%d\n", ans+ans2);
	}
}