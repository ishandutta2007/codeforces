#include <queue>
#include <stdio.h>
using namespace std;
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c=='-' ) c=getchar(),tmp=-1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
struct XD{ int n; }t;
bool operator<( const XD &x , const XD& y ){ return x.n>y.n; }
priority_queue<XD> pQ;
int n,k,sum,tmp;
int main(){
	n = getint(); k = getint();
	while( n-- ){
		tmp = getint(); t.n = tmp; pQ.push( t );
	}
	while( k-- ){
		t = pQ.top(); pQ.pop(); t.n *= -1; pQ.push( t );
	}
	while( pQ.size() ){
		t = pQ.top(); sum += t.n; pQ.pop();
	}
	printf("%d\n",sum);
}