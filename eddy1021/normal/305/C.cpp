#include <stdio.h>
#include <set>
using namespace std;
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
set<int> S;
int n , tmp , Max = -1;
int main(){
	n = getint();
	while( n -- ){
		tmp = getint();
		while( S.count( tmp ) ){
			S.erase( tmp ); tmp ++;
		}
		S.insert( tmp );
		if( tmp > Max ) Max = tmp;
	}
	printf( "%d\n" , Max + 1 - S.size() );
}