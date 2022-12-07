#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define fi first
#define se second
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 200 + 5 ; 
int n, b, top ; 
int query(int x, string t) {
	printf("%d ", x) ;
	for(auto p : t) printf("%c", p) ;
	puts(""), fflush(stdout) ; 
	string ans ; cin >> ans ; 
	return (ans == "yes") ; 
}
pair<int, string> st[N] ; 
void solve(vi id, string pre) {
	if(pre.size() == b) {
		cout << "0 " << pre << endl ; fflush(stdout) ; exit(0) ; 
	}
	top = 0, st[0] = mp(0, pre) ; 
	for(auto p : id) {
		while(top) {
			string z = st[top].se ; 
			while(z.size() < b) z.pb('1') ; 
			if(!query(p, z)) break ; 
			-- top ; 
		}
		if(st[top].se.size() == b) continue ; 
		string ans = st[top].se ; ans.pb('0') ; 
		while(ans.size() < b) ans.pb('1') ; 
		if(query(p, ans)) 
			st[++ top] = mp(p, st[top].se + '1') ; 
		else 
			st[++ top] = mp(p, st[top].se + '0') ; 
	}
	vector<int> Id ; string ans = st[top].se ; 
	for(re int i = top; i >= 1; -- i) {
		string t = ans ; 
		while(t.size() < b) t.pb('1') ;
		if(query(st[i].fi, t)) Id.clear(), Id.pb(st[i].fi), ans = st[i].se ; 
		else Id.pb(st[i].fi) ; 
	} solve(Id, ans) ; 
}
signed main()
{
	n = gi(), b = gi() ;
	vi id ; rep( i, 1, n ) id.pb(i) ; 
	solve(id, "") ; 
	return 0 ;
}
//010 001 100 000 110