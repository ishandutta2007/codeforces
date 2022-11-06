/********************************
please don't hack me!! /(ToT)/~~
                __------__
              /~          ~\
             |    //^\\//^\|
           /~~\  ||  T| |T|:~\
          | |6   ||___|_|_||:|
           \__.  /      o  \/'
            |   (       O   )
   /~~~~\    `\  \         /
  | |~~\ |     )  ~------~`\
 /' |  | |   /     ____ /~~~)\
(_/'   | | |     /'    |    ( |
       | | |     \    /   __)/ \
       \  \ \      \/    /' \   `\
         \  \|\        /   | |\___|
           \ |  \____/     | |
           /^~>  \        _/ <
          |  |         \       \
          |  | \        \        \
          -^-\  \       |        )
               `\_______/^\______/
************************************/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n	2005
#define DB	double
#define MK	make_pair
#define I64	long long
#define unt unsigned int
#define PA	pair<int,int>
#define CH	(ch=getchar())
#define Pt	set<int>::iterator
#define For(i,a,b)	for(int i=a;i<=b;i++)
#define Rep(i,a,b)	for(int i=a;i>=b;i--)

DB		F[n][n];
int		N,M,A[n][n];

int		IN(){
		int x=0,ch;
		for	(;CH<'0'||ch>'9';);
		for	(;ch>='0'&&ch<='9';CH)	(x*=10)+=ch-'0';
		return	x;
}

int		main(){
		scanf("%d%d",&N,&M);
		For(i,1,M)	{
			int x=IN(),y=IN();	A[x][y]=1;
		}
		int X=0,Y=0;
		For(i,1,N)	{
			For(j,1,N)	if	(A[i][j])	{X++;break;}
			For(j,1,N)	if	(A[j][i])	{Y++;break;}
		}

		Rep(i,N,0)	Rep(j,N,0)	if	(i!=N||j!=N){
			DB	p1=(N-i)*(N-j),p2=(N-j)*N-p1,p3=(N-i)*N-p1,p4=N*N-p1-p2-p3;
			p1/=N*N;	p2/=N*N;	p3/=N*N;	p4/=N*N;
			F[i][j]=(F[i+1][j+1]*p1+F[i][j+1]*p2+F[i+1][j]*p3+1)/(1-p4);
		}
		printf("%.10lf\n",F[X][Y]);
}