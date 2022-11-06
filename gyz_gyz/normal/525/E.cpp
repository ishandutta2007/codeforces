#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n	30
#define m	1000005
#define I64	long long
#define MK	make_pair
#define PA	pair<I64,I64>
#define Pt	map<I64,I64>::iterator

PA		tmp[m];
I64		S,Ans,P[n];
int		N,M,K,T,A[n];
map<I64,I64>L[n],R[n];

void	Work1(int l,int r){
		L[0][0]=1;
		for	(int i=l;i<=r;i++)
		for	(int j=K;j+1;j--){
			T=0;
			for	(Pt	it=L[j].begin();it!=L[j].end();it++)
				if	((it->first)<=S)	tmp[++T]=*it;
			for	(int k=1;k<=T;k++)	{
				L[j][tmp[k].first+A[i]]+=tmp[k].second;
				if	(A[i]<20)	L[j+1][tmp[k].first+P[A[i]]]+=tmp[k].second;
			}
		}
}

void	Work2(int l,int r){
		R[0][0]=1;
		for	(int i=l;i<=r;i++)
		for	(int j=K;j+1;j--){
			T=0;
			for	(Pt	it=R[j].begin();it!=R[j].end();it++)
				if	((it->first)<=S)	tmp[++T]=*it;
			for	(int k=1;k<=T;k++)	{
				R[j][tmp[k].first+A[i]]+=tmp[k].second;
				if	(A[i]<20)	R[j+1][tmp[k].first+P[A[i]]]+=tmp[k].second;
			}
		}
}

int		main(){
		scanf("%d%d%I64d",&N,&K,&S); P[0]=1;
		for	(int i=1;i<20;i++)	P[i]=P[i-1]*i;

		for	(int i=1,x;i<=N;i++)	scanf("%d",&A[i]);
		M=N>>1;	Work1(1,M);	Work2(M+1,N);

		for	(int i=0;i<=K;i++)
		for	(int j=0;i+j<=K;j++)
		for	(Pt it=L[i].begin();it!=L[i].end();it++)
			if	((it->first)<=S)	Ans+=(it->second)*R[j][S-(it->first)];
		printf("%I64d\n",Ans);
}