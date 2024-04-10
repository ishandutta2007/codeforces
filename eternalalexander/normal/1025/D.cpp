#include <bits/stdc++.h>

int n,a[705],w[705][705],f[705][705][2];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int dfs(int l,int r,int d){
	if (f[l][r][d]!=-1)return f[l][r][d];
	if (l>r)return 1;
	f[l][r][d]=0;
	for(int i=l;i<=r;++i){
		if (d==0&&w[l-1][i]&&dfs(l,i-1,1)&&dfs(i+1,r,0)){f[l][r][d]=1;return 1;}
		if (d==1&&w[r+1][i]&&dfs(l,i-1,1)&&dfs(i+1,r,0)){f[l][r][d]=1;return 1;}
	}return 0;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
		if (gcd(a[i],a[j])!=1)w[i][j]=1;
	for(int i=1;i<=n;++i)w[0][i]=w[i][0]=1;
	std::memset(f,-1,sizeof(f));
	if (dfs(1,n,0))printf("Yes");
	else printf("No");
	return 0;
}