#include <bits/stdc++.h>
#define maxn 100005
int n,a[maxn],f[305][maxn],q,p,k;
int run(int k,int p){
	int cnt=0;
	while (p<=n){
		cnt++;p+=a[p]+k;
	}return cnt;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=300;++i){
		for(int j=n;j>=1;j--){
			if (j+a[j]+i>n)f[i][j]=1;
			else f[i][j]=f[i][j+a[j]+i]+1;
		}
	}while (q--){
		scanf("%d%d",&p,&k);
		if (k<=300)printf("%d\n",f[k][p]);
		else printf("%d\n",run(k,p));
	}return 0;
}