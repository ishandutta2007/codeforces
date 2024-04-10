#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 1010
#define inf 10000000
struct XDD{
	int tn , tm , p;
}tmp2;
char c[ N ][ N ];
int n , m , dp[ N ][ N ] , dp2[ N ][ N ] , toend[ N ][ N ];
int sn , sm , en , em;
bool vst[ N ][ N ] , vst2[ N ][ N ] , vst3[ N ][ N ] , tag[ N ][ N ];
void init(){
	scanf( "%d%d" , &n , &m );
	for( int i = 1 ; i <= n ; i ++ )
		scanf( "%s" , c[ i ] + 1 );
}
void find_point(){
	int gots = 0, gote = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= m ; j ++ ){
			if( c[ i ][ j ] == 'S' ){
				sn = i; sm = j; gots = 1;
			}else if( c[ i ][ j ] == 'E' ){
				en = i; em = j; gote = 1;
			}
			if( gots && gote ) break;
		}
		if( gots && gote ) break;
	}
}
int dn[]={0,1,0,-1};
int dm[]={1,0,-1,0};
bool cango( int xn , int xm ){
	if( xn < 1 || xm < 1 || xn > n || xm > m ) return false;
	if( c[ xn ][ xm ] == 'T' ) return false;
	return true;
}
void find_road(){
	queue<XDD> Q;
	tmp2.tn = sn; tmp2.tm = sm; tmp2.p = 0;
	Q.push( tmp2 ); vst[ sn ][ sm ] = 1;
	while( Q.size() ){
		tmp2 = Q.front(); Q.pop();
		int yn = tmp2.tn , ym = tmp2.tm , yp = tmp2.p;
		for( int i = 0 ; i < 4 ; i ++ )
			if( cango( yn + dn[ i ] , ym + dm[ i ] )
					&& !vst[ yn + dn[ i ] ][ ym + dm[ i ] ] ){
				tmp2.tn = yn + dn[ i ];
				tmp2.tm = ym + dm[ i ];
				toend[ yn + dn[ i ] ][ ym + dm [ i ] ]
					= tmp2.p = yp + 1;
				vst[ yn + dn[ i ] ][ ym + dm[ i ] ] = 1;
				Q.push( tmp2 );
			}
	}
}
int cal( int xn , int xm ){
	if( c[ xn ][ xm ] >= '0' && c[ xn ][ xm ] <= '9' )
		return c[ xn ][ xm ] - '0';
	return 0;
}
void dp_man( int xn , int xm , int xp ){
	queue<XDD> QQ;
	int sum = 0;
	tmp2.tn = xn; tmp2.tm = xm; tmp2.p = xp;
	QQ.push( tmp2 ); tag[ xn ][ xm ] = 1;
	while( QQ.size() ){
		tmp2 = QQ.front(); QQ.pop();
		int yn = tmp2.tn , ym = tmp2.tm , yp = tmp2.p;
		for( int i = 0 ; i < 4 ; i ++ )
			if( cango( yn + dn[ i ] , ym + dm[ i ] )
					&& !tag[ yn + dn[ i ] ][ ym + dm[ i ] ] ){
				sum += cal( yn + dn[ i ] , ym + dm[ i ] );
				tmp2.tn = yn + dn[ i ];
				tmp2.tm = ym + dm[ i ];
				tmp2.p = yp - 1;
				tag[ yn + dn[ i ] ][ ym + dm[ i ] ] = 1;
				if( tmp2.p > 0 ) QQ.push( tmp2 );
			}
	}
	dp[ xn ][ xm ] = sum;
}
void tag_road(){
	queue<XDD> Q;
	tmp2.tn = en; tmp2.tm = em; tmp2.p = toend[ en ][ em ];
	Q.push( tmp2 ); vst2[ en ][ em ] = 1;
	dp_man( en , em , toend[ en ][ em ] );
	while( Q.size() ){
		tmp2 = Q.front(); Q.pop();
		int yn = tmp2.tn , ym = tmp2.tm , yp = tmp2.p;
		for( int i = 0 ; i < 4 ; i ++ )
			if( cango( yn + dn[ i ] , ym + dm[ i ] )
				&& !vst2[ yn + dn[ i ] ][ ym + dm[ i ] ]
				&& toend[ yn + dn[ i ] ][ ym + dm[ i ] ] == yp - 1 ){
				tmp2.tn = yn + dn[ i ];
				tmp2.tm = ym + dm[ i ];
				tmp2.p = yp - 1;
				Q.push( tmp2 );
				vst2[ yn + dn[ i ] ][ ym + dm[ i ] ] = 1;
				dp_man( yn + dn[ i ] , ym + dm[ i ] , yp - 1 );
			}
	}
}
void dp_ans(){
	queue<XDD> Q2;
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= m ; j ++ )
			dp2[ i ][ j ] = inf;
	tmp2.tn = sn; tmp2.tm = sm; Q2.push( tmp2 );
	dp2[ sn ][ sm ] = 0; vst3[ sn ][ sm ] = 1;
	while( Q2.size() ){
		tmp2 = Q2.front(); Q2.pop();
		int yn = tmp2.tn , ym = tmp2.tm;
		for( int i = 0 ; i < 4 ; i ++ )
			if( cango( yn + dn[ i ] , ym + dm[ i ] ) &&
				!vst3[ yn + dn[ i ] ][ ym + dm[ i ] ] && 
				toend[ yn + dn[ i ] ][ ym + dm[ i ] ] == toend[ yn ][ ym ] + 1 &&
				dp2[ yn ][ ym ] + dp[ yn + dn[ i ] ][ ym + dm[ i ] ]
					< dp2[ yn + dn[ i ] ][ ym + dm[ i ] ] ){
				dp2[ yn + dn[ i ] ][ ym + dm[ i ] ] =
					dp2[ yn ][ ym ] + dp[ yn + dn[ i ] ][ ym + dm[ i ] ];
				tmp2.tn = yn + dn[ i ];
				tmp2.tm = ym + dm[ i ];
				vst3[ yn + dn[ i ] ][ ym + dm[ i ] ] = 1;
				Q2.push( tmp2 );
			}
	}
}
void print(){
	if( dp2[ en ][ em ] == inf ) puts( "-1" );
	else printf( "%d\n" , dp2[ en ][ em ] );
}
int main(){
	init();
	find_point();
	find_road();
	tag_road();
	dp_ans();
	print();
}