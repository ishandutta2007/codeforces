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
#define int long long
int gi() {
char cc = getchar() ; int cn = 0, flus = 1 ;
while( cc < '0' || cc > '9' ) { if( cc == '-' ) flus = - flus ; cc = getchar() ; }
while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
return cn * flus ;
}
const int N = 2e5 + 5 ;
const int M = (1 << 22) + 5 ;
int n, m, T, limit, t[25], a[25][25], f[M], bef[25] ;
char s[N] ;
set<pi> D ;
set<pi>::iterator it ;
void add(int u, int v, int S, int z) {
f[S] += z, f[S ^ (1 << u)] -= z, f[S ^ (1 << v)] -= z, f[S ^ (1 << u) ^ (1 << v)] += z ;
}
void Add(int u, int S, int z) {
f[S] += z, f[S ^ (1 << u)] -= z ;
}
signed main()
{
n = gi(), m = gi(), T = gi(), limit = (1 << m) - 1 ;
scanf("%s", s + 1) ;
rep( i, 0, m - 1 ) t[i] = gi() ;
rep( i, 0, m - 1 ) rep( j, 0, m - 1 ) a[i][j] = gi() ;
rep( i, 1, n ) s[i] -= 'A' ;
for(int i = n; i >= 1; -- i) {
it = D.begin() ; int tf = 0 ;
for(; it != D.end(); ++ it) {
if((*it).se == s[i]) {
Add((*it).se, limit ^ tf, a[(int)s[i]][(int)s[i]] ) ; break ;
}
add(s[i], (*it).se, limit ^ tf, a[(int)s[i]][(*it).se]) ;
tf ^= (1 << (*it).se) ;
}
if(bef[(int)s[i]]) D.erase(mp(bef[(int)s[i]], (int)s[i])) ;
bef[(int)s[i]] = i ; D.insert(mp(i, (int)s[i])) ;
} int o = 0 ;
rep( i, 0, m - 1 ) if(!bef[i]) o |= (1 << i) ;
for(re int k = 1; k <= limit; k <<= 1)
rep( i, 0, limit ) if(!(i & k)) f[i] += f[i ^ k] ;
int Ans = 0 ;
rep( i, 1, limit ) {
int S = (limit ^ i), z = f[i] ;
if((i & o) != o || i == o) continue ;
rep( j, 0, m - 1 ) if(((1 << j) & S)) z += t[j] ;
if(z <= T) ++ Ans ;
}
//se
cout << Ans << endl ;
return 0 ;
}