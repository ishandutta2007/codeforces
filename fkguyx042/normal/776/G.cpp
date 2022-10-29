#include	<bits/stdc++.h>

using	namespace	std;

#define DB		double
#define	lf		else if
#define I64		long long
#define	Rd()	(rand()<<15|rand())
#define For(i,a,b)	for(int i=a,lim=b;i<=lim;i++)
#define Rep(i,a,b)	for(int i=a,lim=b;i>=lim;i--)

#define	fi	first
#define se	second
#define MK	make_pair
#define pb	push_back
#define PA	pair<int, int>

//#define	min(a,b)	((a)<(b)?(a):(b))
//#define	max(a,b)	((a)<(b)?(b):(a))

#define	CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for	(; CH < '0' || ch > '9';)	f= (ch == '-');
		for	(; ch >= '0' && ch <= '9'; CH)	x= x*10 + ch -'0';
		return	f? -x : x;
}

#define n	25

int		A[n];

I64		F[n][2][2];

I64		Dp(int s)	{
		For(i, 0, 20)	For(a, 0, 1)	For(b, 0, 1)	F[i][a][b]= 0;
		F[0][1][0]= 1;
		
		For(i, 1, 20)	For(a, 0, 1)	For(b, 0, 1)	{
			I64 v= F[i-1][a][b];
			if	(! v)	continue;
			
			For(c, 0, s)	{
				if	(4 * (i-1) <= s && s < 4*i)	{
					if	((c >> (s - 4 * (i-1))) % 2 == 0)	continue;
				}
				
				F[i][c < A[i] || (c == A[i] && a)][b || c == s]+= v;
			}
		}
		
		return	F[20][1][1];
}

I64		Cal(I64 M)	{
		if	(M <= 0)	return	0;
		
		For(i, 1, 20)	A[i]= 0;
		For(i, 1, 20)	A[i]= M&15, M>>= 4;
		
		I64	ret= 0;
		For(s, 0, 15)	ret+= Dp(s);
		
		return	ret;
}

int		main(int argc, char* argv[]){
		for (int Q= IN(); Q --;)	{
			I64	x, y;
			
			scanf("%llx%llx", &x, &y);
			printf("%lld\n", Cal(y) - Cal(x-1));
		}
		
		return	0;
}