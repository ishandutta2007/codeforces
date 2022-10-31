#include <stdio.h>
#define N 100010
#define M 510
#define ll long long
bool p[N]; int pt,n,m,cntn[M],cntm[M],amin=N,tmp,dlt,ST[N<<2];
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int min( int x , int y ){ return x<y?x:y; }
void build_ST( int no , int l , int r ){
	if( l==r ){
		if( !p[l] ) ST[no] = l;
		else ST[no] = N;
		return;
	}
	int m = ( l+r )>>1;
	build_ST( no<<1 , l , m );
	build_ST( (no<<1)+1 , m+1 , r );
	ST[no] = min( ST[no<<1] , ST[(no<<1)+1] );
}
void build(){
	for( ll i=2;i<N;i++ ) if( !p[i] )
		for( ll j=i;j*i<N;j++ ) p[ i*j ] = true;
	p[1] = true; build_ST( 1 , 1 , N-1 );
}
int query_ST( int no , int l , int r , int ql , int qr ){
	if( l==ql && r==qr ) return ST[no];
	int m = ( l+r )>>1;
	if( qr<=m ) return query_ST( no<<1 , l , m , ql , qr );
	if( m<ql ) return query_ST( (no<<1)+1 , m+1 , r , ql , qr );
	return min( query_ST( no<<1 , l , m , ql , m ) ,
			query_ST( (no<<1)+1 , m+1 , r , m+1 , qr ) );
}
int main(){
	build(); n = getint(); m = getint();
	for( int i=0;i<n;i++ ) for( int j=0;j<m;j++ ){
		tmp = getint(); dlt = query_ST( 1 , 1 , N-1 , tmp , N-1 ); dlt -= tmp;
		cntn[i] += dlt; cntm[j] += dlt;
	}
	for( int i=0;i<n;i++ ) if( cntn[i]<amin ) amin = cntn[i];
	for( int j=0;j<m;j++ ) if( cntm[j]<amin ) amin = cntm[j];
	printf("%d\n",amin);
}