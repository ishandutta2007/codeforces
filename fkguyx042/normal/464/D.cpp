#include <cstdio>
using namespace std;

#define n	605
#define DB	double

int		N,M;
DB		F[2][n];

int		main(){
		scanf("%d%d",&N,&M);
		for	(int i=N;i;i--){
			int p=i&1,q=p^1;
			for	(int j=1;j<=600;j++)
				F[p][j]=1.*(M-1)/M*F[q][j]+1./M*(1./(j+1)*(F[q][j+1]+j)+1.*j/(j+1)*F[q][j]+j*.5);
		}	printf("%.9lf\n",F[1][1]*M);
}