#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define int long long
#define MAXN 100005

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

int n,a[3][MAXN],f[5][MAXN]; 

int getSum (int t,int l,int r){
	if (l > r) swap (l,r);int sum = 0;
	for (Int i = l;i <= r;++ i) sum += a[i][t];
	return sum;
}

signed main(){
//	freopen ("data.in","r",stdin);
//	freopen ("f1.out","w",stdout);
	read (n);
	for (Int i = 0;i < 3;++ i)
		for (Int k = 1;k <= n;++ k) read (a[i][k]);
	memset (f,0xcf,sizeof (f)),f[0][0] = 0;
	for (Int i = 1;i <= n;++ i){
		for (Int j = 0;j < 3;++ j)
			for (Int k = 0;k < 3;++ k)
				chkmax (f[j][i],f[k][i - 1] + getSum (i,j,k));
		chkmax (f[0][i],max (f[3][i - 1] + a[0][i],f[4][i - 1] + getSum (i,0,2)));
		chkmax (f[2][i],max (f[3][i - 1] + getSum (i,0,2),f[4][i - 1] + a[2][i]));
		chkmax (f[1][i],max (f[3][i - 1] + getSum (i,0,1),f[4][i - 1] + getSum (i,1,2)));
		chkmax (f[3][i],f[2][i - 2] + getSum (i - 1,0,2) + getSum (i,0,2));
		chkmax (f[4][i],f[0][i - 2] + getSum (i - 1,0,2) + getSum (i,0,2));
	} 
	write (max (f[2][n],f[4][n])),putchar ('\n');
	return 0;
}