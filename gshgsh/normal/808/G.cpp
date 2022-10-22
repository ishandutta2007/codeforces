#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
#define MAXM 20000001
int N,M,nxt[MAXN],trie[MAXN][26],pool[MAXM],*f[MAXN];bool can[MAXN][26];
int main()
{
	string s,t;cin>>s>>t;N=s.length();For(i,1,N)if(s[i-1]!='?')can[i][s[i-1]-'a']=1;else For(j,0,25)can[i][j]=1;
	int j=0;M=t.length();For(i,2,M){while(j&&t[i-1]!=t[j])j=nxt[j];nxt[i]=j+=t[i-1]==t[j];}if(N<M){cout<<"0\n";return 0;}
	trie[0][t[0]-'a']=1;For(i,1,M)For(j,0,25)if(i<M&&t[i]==j+'a')trie[i][j]=i+1;else trie[i][j]=trie[nxt[i]][j];
	For(i,0,N)f[i]=pool+i*(M+1);For(i,0,N)For(j,0,M)f[i][j]=-N;f[0][0]=0;
	For(i,0,N-1)For(j,0,M)For(k,0,25)if(can[i+1][k]){int x=trie[j][k];f[i+1][x]=max(f[i+1][x],f[i][j]+(x==M));}
	int ans=0;For(i,0,M)ans=max(ans,f[N][i]);cout<<ans<<'\n';return 0;
}