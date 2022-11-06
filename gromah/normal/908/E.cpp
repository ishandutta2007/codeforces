#include<bits/stdc++.h>
using namespace std;
const int maxn=1011,p=1000000007;
int C[maxn][maxn],f[maxn];
void preset(){
	int n=1000; C[0][0]=1;
	for (int i=1;i<=n;++i){
		C[i][i]=1; C[i][0]=1;
		for (int j=1;j<i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	
	
	f[0]=1; f[1]=1;
	for (int i=1;i<=n;++i) for (int j=0;j<=i;++j) f[i+1]=(f[i+1]+1LL*f[j]*C[i][j])%p;
}
int main(){
	preset(); int m,n;
	static char s[maxn][maxn];
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;++i) scanf("%s",s[i]+1);
	static map<string,int>mp;
	for (int i=1;i<=m;++i){
		string S="";
		for (int j=1;j<=n;++j) S+=s[j][i];
		mp[S]++;
	}
	int ans=1;
	for (auto x=mp.begin();x!=mp.end();++x){
		ans=1LL*ans*f[x->second]%p;
	}
	printf("%d\n",ans);
}