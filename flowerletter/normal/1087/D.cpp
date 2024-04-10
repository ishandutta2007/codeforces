#include <bits/stdc++.h>
using namespace std;
int du[100010],n,s;
int main(){
	cin>>n>>s;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		du[u]++,du[v]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++) if(du[i]==1) sum++;
	double ans=(double)s/(double)sum*2;
	printf("%lf\n",ans);
	return 0;
}