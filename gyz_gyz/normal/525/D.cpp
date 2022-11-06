#include <bits/stdc++.h>

#define	st first
#define	nd second
#define	mp make_pair
#define	pb push_back
#define	lli long long int
#define	all( gg )	gg.begin(),gg.end()
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	FP( ii,aa,bb ) for( lli ii=aa;ii<=bb;ii++ )
#define	FM( ii,aa,bb ) for( lli ii=aa;ii>=bb;ii-- )
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;

#define	ctrl( xx,yy )	( xx>=1 and yy>=1 and xx<=m and yy<=n and s[xx][yy]=='.' )

#define	mod	1000000007LL

using namespace std;

int	m,n;
char	s[3000][3000];
char	h[3000][3000];

int	bozuk( int x,int y ){
	if( s[x][y]!='*' )	return	0;
	if( ctrl( x-1,y ) and ctrl( x-1,y+1 ) and ctrl( x,y+1 ) )	return	1;
	if( ctrl( x,y+1 ) and ctrl( x+1,y+1 ) and ctrl( x+1,y ) )	return	1;
	if( ctrl( x+1,y ) and ctrl( x+1,y-1 ) and ctrl( x,y-1 ) )	return	1;
	if( ctrl( x,y-1 ) and ctrl( x-1,y-1 ) and ctrl( x-1,y ) )	return	1;
	return	0;
}

int main(){
	cin >> m >> n;
	FP( i,1,m )
		scanf("%s",s[i]+1);
	queue< pair<int,int> >	Q;
	FP( i,1,m )
		FP( j,1,n )
			if( bozuk( i,j ) )	Q.push( mp(i,j) ),h[i][j]=1;
	int	x,y,xx,yy;
	while( Q.size() ){
		x = Q.front().st;
		y = Q.front().nd;
		Q.pop();
		s[x][y] = '.';
		h[x][y] = 0;
		FP( i,-1,1 )
			FP( j,-1,1 ){
				if( !i and !j )	continue;
				xx = x+i;
				yy = y+j;
				if( xx<1 or xx>m or yy<1 or yy>n or h[xx][yy] or !bozuk( xx,yy ) )	continue;
				Q.push( mp(xx,yy) ),h[xx][yy] = 1;
				s[xx][yy] = '.';
			}
	}
	FP( i,1,m )
		printf("%s\n",s[i]+1);
}