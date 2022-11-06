#include<bits/stdc++.h>
using namespace std;
typedef double ld;
int n,m,k;
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n>>m>>k;
	if(k>=m)return puts("1.0000"),0;
	ld an=1;
	int a,b,i;
	a=m-k,b=n+1;
	for(i=1;i<=k+1;++i,++a,++b){
		an=an*a/b;
	}
	printf("%.6lf\n",max(0.0,1-an));
}