#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 998244353 ; 
const int I = 499122177 ; 
const int I6 = 166374059 ; 
const int N = 1e6 + 5 ; 
int n, f[N], S[N] ; 
int sq3(int x) { return x * x % P * x % P ; }
int sq2(int x) { return x * x % P ; }
signed main()
{
	n = gi(), f[0] = S[0] = 1, f[1] = 2, S[1] = 3 ; 
	if(n == 1) { puts("5") ; exit(0) ; }
	rep( i, 2, n ) 
		f[i] = (I * ((sq2(S[i - 1]) - sq2(S[i - 2]) + f[i - 1] + P) % P) % P + f[i - 1]) % P,
		S[i] = (S[i - 1] + f[i]) % P ; 
	int ans = 0 ; 
	ans = f[n] + I6 * (
		(sq3(S[n - 1]) - sq3(S[n - 2]) + P) % P
		+ 2 * f[n - 1] % P
		+ 3 * (sq2(S[n - 1]) - sq2(S[n - 2]) + P) % P) % P ;
	ans %= P ; 
	int num = (ans * 2 + P - 1) % P ; 
	rep( i, 1, n - 2 ) 
	num = (num + (f[i] - f[i - 1] + P) * (f[n - i - 1] - 1)) % P ; 
	cout << num << endl ; 
	return 0 ;
}