#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,m,a[N],nxt[N][27],las[N][27];
int dp[N][27],fs[N];
char s[N];
int tmp[27];
int calc(int i,int j,int c,int op){
	if(~tmp[c])return tmp[c];
	int st=0;
	for(int z=0;z<26;++z){
		int l=nxt[i][z],r=las[j][z];
		if(l<j){
			st|=1<<((op?dp[i][z]:calc(i,l,z,0))^fs[l]^fs[r]^(op?calc(r+1,j,z,1):dp[r+1][c]));
		}
	}
	for(int x=0;;++x){
		if(!(st>>x&1)){
			return tmp[c]=x;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'a';
	}
	for(int i=0;i<=26;++i)nxt[n+1][i]=n+1;
	for(int i=n;i>=1;--i){
		memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
		nxt[i][a[i]]=i;
	}
	for(int i=2;i<=n+1;++i){
		memcpy(las[i],las[i-1],sizeof(las[i]));
		las[i][a[i-1]]=i-1;
	}
	for(int i=n+1;i>=1;--i){
		fs[i]=fs[nxt[i+1][a[i]]]^dp[i+1][a[i]];
		for(int j=0;j<=26;++j){
			memset(tmp,-1,sizeof(tmp));
			dp[i][j]=calc(i,nxt[i][j],j,0);
		}
	}
	cin>>m;
	while(m--){
		int i,j;
		cin>>i>>j;
		memset(tmp,-1,sizeof(tmp));
		cout<<(calc(i,j+1,26,1)?"Alice\n":"Bob\n");
	}
	return 0;
}