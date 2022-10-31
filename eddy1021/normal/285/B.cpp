#include <queue>
#include <stdio.h>
using namespace std;
#define N 100100
#define inf 1000000000
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int dst[ N ] , n , s , t , nxt[ N ] , tn;
bool inq[ N ];
void SPFA(){
	queue<int> Q; dst[ s ] = 0; Q.push( s );
	while( Q.size() ){
		tn = Q.front(); Q.pop(); inq[ tn ] = 0;
		if( dst[tn] + 1 < dst[ nxt[tn] ] ){
			dst[nxt[tn]] = dst[tn] + 1;
			if( !inq[nxt[tn]] ){
				inq[nxt[tn]] = 1; Q.push(nxt[tn]);
			}
		}
	}
}
int main(){
	n = getint(); s = getint(); t = getint();
	for( int i=1;i<=n;i++ ){
		nxt[i] = getint(); dst[i] = inf;
	}
	SPFA();
	if( dst[ t ] == inf ) puts("-1");
	else printf("%d\n",dst[ t ]);
}