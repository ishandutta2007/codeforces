#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int c[210];
char in[210][210];
int len[210];
struct Trie{
	int chi[26];
	int sc;
	Trie(){for(int i=0;i<26;i++)chi[i]=-1;sc=0;}
};
Trie pool[210];
char st[210];
int n;
int to[210][26];
void dfs(int a,int b){
	for(int i=0;i<26;i++){
		if(pool[a].chi[i]==-1)continue;
		st[b]='a'+i;
		dfs(pool[a].chi[i],b+1);
	}
	for(int i=0;i<n;i++){
		if(len[i]>b)continue;
		bool ok=true;
		for(int j=0;j<len[i];j++){
			if(in[i][len[i]-1-j]!=st[b-1-j]){ok=false;break;}
		}
		if(ok)pool[a].sc+=c[i];
	}
	for(int i=0;i<26;i++){
		st[b]=i+'a';
		bool ok=false;
		for(int j=0;j<=b;j++){
			int now=0;
			for(int k=j;k<=b;k++){
				if(pool[now].chi[st[k]-'a']==-1){now=-1;break;}
				now=pool[now].chi[st[k]-'a'];
			}
			if(now!=-1){
				ok=true;to[a][i]=now;break;
			}
		}
		if(!ok)to[a][i]=0;
	}
}
long long dp[210][210][210];
long long val[210][410];
long long las[210][210];
int main(){
	int a;
	long long b;
	scanf("%d%I64d",&a,&b);
	n=a;
	for(int i=0;i<a;i++)scanf("%d",c+i);
	for(int i=0;i<a;i++){
		scanf("%s",in[i]);
		len[i]=strlen(in[i]);
	}
	int sz=1;
	for(int i=0;i<a;i++){
		int at=0;
		for(int j=0;in[i][j];j++){
			if(pool[at].chi[in[i][j]-'a']==-1){
				pool[at].chi[in[i][j]-'a']=sz++;
				at=sz-1;
			}else at=pool[at].chi[in[i][j]-'a'];
		}
	}
	dfs(0,0);
	for(int i=0;i<sz;i++){
		for(int j=0;j<210;j++)for(int k=0;k<210;k++)dp[i][j][k]=-mod;
		dp[i][0][i]=0;
		for(int j=0;j<sz;j++){
			for(int k=0;k<sz;k++){
				for(int l=0;l<26;l++){
					dp[i][j+1][to[k][l]]=max(dp[i][j+1][to[k][l]],dp[i][j][k]+pool[to[k][l]].sc);
				}
			}
		}
	}
	long long ret=0;
	for(int i=0;i<sz;i++){
		for(int j=0;j<410;j++){
			val[i][j]=-inf;
			if(b-j<0)continue;
			for(int k=1;k<=sz;k++){
				if(dp[i][k][i]<0)continue;
				val[i][j]=max(val[i][j],(b-j)/k*dp[i][k][i]);
			}
		}
	}
	if(b<sz){
		for(int i=0;i<sz;i++)ret=max(ret,dp[0][b][i]);
		printf("%I64d\n",ret);
		return 0;
	}
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++){
			las[i][j]=-inf;
			for(int k=0;k<sz;k++)las[i][j]=max(las[i][j],dp[i][j][k]);
		}
	}
	for(int i=0;i<sz;i++){
		for(int j=0;j<sz;j++)for(int k=0;k<sz;k++){
			ret=max(ret,dp[0][j][i]+val[i][j+k]+las[i][k]);
		}
	}
	printf("%I64d\n",ret);
}