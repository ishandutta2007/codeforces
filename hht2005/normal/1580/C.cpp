#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,T=477;
int x[N],y[N],f[T+10][T+10],d[N],las[N];
int main() {
	int n,m,op,k,sum=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&op,&k);
		if(op==1)op=1,las[k]=i;
		else op=-1;//lkujygahfsgjrdukftljh
		if(x[k]+y[k]>=T) {
			for(int j=las[k];j+x[k]<=m;j+=x[k]+y[k]) {
				if(j+x[k]<i)sum+=op;
				else d[j+x[k]]+=op;
				if(j+x[k]+y[k]<i)sum-=op;
				else if(j+x[k]+y[k]<=m)d[j+x[k]+y[k]]-=op;
			}
		} else {
			for(int i=las[k]+x[k];i<las[k]+x[k]+y[k];i++)
				f[x[k]+y[k]][i%(x[k]+y[k])]+=op;
		}
		sum+=d[i];
		int S=0;
		for(int j=1;j<T;j++)
			S+=f[j][i%j];
		printf("%d\n",sum+S);
	}
	return 0;
}