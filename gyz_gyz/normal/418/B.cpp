#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n	105
#define m	2000005
#define INF	(1ll<<60)
#define I64	long long

int		N,M,B;
I64		Ans,F[m];
struct	Nod{int x,k,s;}A[n];

bool	Cmp(Nod a,Nod b)	{return	a.k<b.k;}

int		main(){
		scanf("%d%d%d",&N,&M,&B);
		for	(int i=1,t;i<=N;i++){
			scanf("%d%d%d",&A[i].x,&A[i].k,&t);
			for	(int x;t--;)	scanf("%d",&x),A[i].s|=1<<x-1;
		}	sort(A+1,A+N+1,Cmp);int U=1<<M;Ans=INF;

		for	(int i=1;i<U;i++)	F[i]=INF;
		for	(int i=1;i<=N;i++){
			for	(int j=0;j<U;j++)
				if	(F[j]!=INF)	F[j|A[i].s]=min(F[j|A[i].s],F[j]+A[i].x);
			if	(F[U-1]!=INF)	Ans=min(Ans,F[U-1]+1ll*A[i].k*B);
		}	printf("%I64d\n",Ans==INF?-1:Ans);
}