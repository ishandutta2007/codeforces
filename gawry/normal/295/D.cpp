#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
const int MAX=2010;
const int MOD=1000000000+7;
int ways[MAX][MAX],ways2[MAX][MAX];
main(){
	scanf("%d %d",&n,&m);
	if(m<2){
		puts("0");
		return 0;
	}
	--m;
	for(int i=1;i<=m;i++)ways[1][i]=ways2[1][i]=1;
	for(int i=2;i<=n;i++){
		long long sum=0,add=0;
		for(int j=1;j<=m;j++){
			ways2[i][j]=(sum*j+MOD-add)%MOD;
			sum=(sum+ways[i-1][j])%MOD;
			add=(add+(long long)ways[i-1][j]*(j-1))%MOD;
			ways[i][j]=(sum*j+MOD-add)%MOD;
		}
	}
//	cout<<ways[1][1]<<" "<<ways2[1][1]<<endl;
	int ans=0;
	for(int i=1;i<=m;i++){
		long long cur=0,sum=0,add=0;
		for(int j=n;j>=1;j--){
			int k=n-j+1;
			add=(add+(long long)ways2[k][i]*(n+2-k))%MOD;
			sum=(sum+ways2[k][i])%MOD;
			cur=(cur+(long long)ways[j][i]*(add+MOD-sum*j%MOD))%MOD;
//for(int k=1;j+k-1<=n;k++){
			//cur=(cur+(long long)ways[j][i]*ways2[k][i]%MOD*(n-j+2-k))%MOD;
//			}
		}
		ans=(ans+cur*(m-i+1))%MOD;
	}
	printf("%d\n",ans);
}