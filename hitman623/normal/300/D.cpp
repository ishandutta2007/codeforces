#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI 3.141592653589793l
using namespace std;
const long mod = 7340033 ;
const long root = 5 ;                // nth root of unity ...   (root^n=1)
const long root_1 = 4404020 ;        // inverse of nth root of unity  ... root^-1
const long root_pw = 1 << 20 ;       // maximum n value
long binpow ( long a, long n) {
	long res = 1 ;
	while ( n ) {
		if ( n & 1 )
			res=(res*a)%mod;
		a=(a*a)%mod;
		n >>= 1 ;
	}
	return res ;
}
void fft ( vector < long > & a, bool invert ) {
	long n = ( long ) a. size ( ) ;

	for ( long i = 1 , j = 0 ; i < n ; ++ i ) {
		long bit = n >> 1 ;
		for ( ; j >= bit ; bit >>= 1 )
			j -= bit ;
		j += bit ;
		if ( i < j )
			swap ( a [ i ] , a [ j ] ) ;
	}

	for ( long len = 2 ; len <= n ; len <<= 1 ) {
		long wlen = invert ? root_1 : root ;
		for ( long i = len ; i < root_pw ; i <<= 1 )
			wlen = ( wlen * wlen % mod ) ;
		for ( long i=0 ; i < n ; i += len ) {
			long w = 1 ;
			for ( long j = 0 ; j < len / 2 ; ++ j ) {
				long u = a [ i + j ] ,  v = (long) ( a [ i + j + len / 2 ] * w % mod ) ;
				a [ i + j ] = (u+v+mod)%mod ;
				a [ i + j + len / 2 ] = (u-v+mod)%mod  ;
				w = ( w * wlen % mod ) ;
			}
		}
	}
	if ( invert ) {
		long nrev = binpow(n,mod-2) ;
		for ( long i = 0 ; i < n ; ++ i )
			a [ i ] = ( a [ i ] * nrev % mod ) ;
	}
}
void multiply ( const vector < long > & a, const vector < long > & b, vector < long > & res ) {
	vector < long > fa ( a. begin ( ) , a. end ( ) ) ,  fb ( b. begin ( ) , b. end ( ) ) ;
	size_t n = 1 ;
	while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ;
	n <<= 1 ;
	fa. resize ( n ) ,  fb. resize ( n ) ;
	fft ( fa , false ) , fft ( fb , false ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		fa [ i ] *= fb [ i ] ;
	fft ( fa, true ) ;
	res. resize ( n ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		res [ i ] = fa [ i ] ;
}
long f[33][1005];
void solve(long n,long k)
{
    long i;
    if(f[n][k]!=-1) return;
    if(n==1) {f[n][k]=(k==0);return ;}
    if(k==0) {f[n][k]=1;return ;}
    for(i=0;i<=k;++i)
    solve(n-1,k-i);
    vl p1(k+1),p2(k+1),p3(k+1);
    for(i=0;i<=k;++i)
    {
        p1[i]=f[n-1][i]%mod;
        p2[i]=f[n-1][i]%mod;
    }
    multiply(p1,p2,p3);
    for(i=0;i<=k;++i)
    {
        p1[i]=p3[i]%mod;
        p2[i]=p3[i]%mod;
    }
    multiply(p1,p2,p3);
    for(i=k;i>0;--i)
    f[n][i]=p3[i-1];
}
int main()
{
    io
    long q,n,k,i,c;
    memset(f,-1,sizeof f);
    solve(31,1003);
    cin>>q;
    while(q--)
    {
        c=0;
        cin>>n>>k;
        while(n%2 && n>1)
        n/=2,c++;
        cout<<f[c+1][k]<<"\n";
    }
    return 0;
}