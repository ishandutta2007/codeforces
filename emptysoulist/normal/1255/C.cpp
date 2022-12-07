#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
//#define int long long
inline int gi() {
	int cn = 0, flus = 1 ; char cc = getchar() ;
	while( cc > '9' || cc < '0' ) { if( cc == '-' ) flus = -flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ; 
}
const int N = 1e5 + 5 ; 
int n, vis[N], ans[N], book[N], Can[N], Go[N] ; 
vector<int> rm[N] ;
struct Q {
    int a, b, c ; 
} q[N] ; 
queue<int> U ; 
signed main() {
    n = gi() ; 
    rep( i, 3, n ) {
    q[i].a = gi(), q[i].b = gi(), q[i].c = gi(), 
    ++ book[q[i].a], ++ book[q[i].b], ++ book[q[i].c] ; 
    rm[q[i].a].push_back(i), rm[q[i].b].push_back(i), rm[q[i].c].push_back(i) ;
    }
    int fl = 0 ; 
    rep( i, 1, n ) {
        Can[i] = book[i] ; 
        if( book[i] == 1 && fl == 0 ) U.push(i), fl = 1 ;
        else if( book[i] == 1 ) vis[i] = 1, ans[n] = i ; 
    }
    int tot = 0 ;
    while(!U.empty()) {
        int u = U.front() ; U.pop() ; 
        vis[u] = 1, ans[++ tot] = u ; 
        for( re int i = 0; i < rm[u].size(); ++ i ) {
            int v = rm[u][i] ; if( Go[v] ) continue ; 
            Go[v] = 1 ; 
            -- book[q[v].a], -- book[q[v].b], -- book[q[v].c] ;
            if( Can[u] >= 2 ) {
                if( !vis[q[v].a] && book[q[v].a] == 1 && Can[q[v].a] == 3 ) U.push(q[v].a) ;
                if( !vis[q[v].b] && book[q[v].b] == 1 && Can[q[v].b] == 3 ) U.push(q[v].b) ;
                if( !vis[q[v].c] && book[q[v].c] == 1 && Can[q[v].c] == 3 ) U.push(q[v].c) ;
            }
            else {
                if( !vis[q[v].a] && book[q[v].a] == 1 ) U.push(q[v].a) ;
                if( !vis[q[v].b] && book[q[v].b] == 1 ) U.push(q[v].b) ;
                if( !vis[q[v].c] && book[q[v].c] == 1 ) U.push(q[v].c) ;
            }
        }
    }
    rep( i, 1, n ) if( !vis[i] ) ans[n - 1] = i ;
    rep( i, 1, n ) printf("%d ", ans[i] ) ;

    return 0 ; 
}