#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
double L, H ; 
signed main()
{
	H = read(), L = read() ; 
	double X = ( L * L + H * H ) / ( 2.0 * H ) ;
	printf("%.10lf", X - H )  ; 
	return 0;
}
//x^2=L^2+(x-H)^2
//x^2=L^2+x^2+H^2-2*Hx
//