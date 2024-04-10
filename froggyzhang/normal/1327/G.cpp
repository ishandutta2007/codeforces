#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
#define N 2010
const ll inf=0x3f3f3f3f3f3f3fll;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,tot,pos[233],k,to[N][233],cnt[1<<14];
ll dp[N][1<<14],sum[N][233];
queue<int> q;
char s[N*N];
struct AC_automation{
	int ch[14],nxt;
	ll val;
}trie[N];
void Insert(char *s,int x){
	int u=1;
	int len=strlen(s+1);
	for(int i=1;i<=len;++i){
		int c=s[i]-'a';
		if(!trie[u].ch[c])trie[u].ch[c]=++tot;
		u=trie[u].ch[c];
	}
	trie[u].val+=x;
}
void init(){
	for(int i=0;i<14;++i){
		trie[0].ch[i]=1;
	} 
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<14;++i){
			int v=trie[u].ch[i];
			if(v){
				trie[v].nxt=trie[trie[u].nxt].ch[i];
				trie[v].val+=trie[trie[v].nxt].val;
				q.push(v);
			} 
			else{
				trie[u].ch[i]=trie[trie[u].nxt].ch[i];
			}
		}
	} 
}
ll Solve(char *s){
	int len=strlen(s+1);
	for(int i=1;i<=len;++i){
		if(s[i]=='?'){
			pos[++k]=i;
		}
	}
	pos[k+1]=len+1;
	for(int i=1;i<=tot;++i){
		for(int j=0;j<=k;++j){
			int u=i;
			sum[i][j]+=trie[i].val;
			for(int p=pos[j]+1;p<pos[j+1];++p){
				int c=s[p]-'a';
				u=trie[u].ch[c];
				sum[i][j]+=trie[u].val;
			}
			to[i][j]=u;
		}
	}
	memset(dp,~0x2f,sizeof(dp));
	dp[to[1][0]][0]=sum[1][0];
	for(int i=0;i<(1<<14);++i){
		cnt[i]=(cnt[i>>1]+(i&1));
		if(cnt[i]>=k)continue;
		for(int j=1;j<=tot;++j){
			for(int c=0;c<14;++c){
				if(i&(1<<c))continue;
				int u=trie[j].ch[c];
				ll &tmp=dp[to[u][cnt[i]+1]][i|(1<<c)];
				tmp=max(tmp,dp[j][i]+sum[u][cnt[i]+1]);
			}
		}
	}
	ll ans=-inf;
	for(int i=0;i<(1<<14);++i){
		if(cnt[i]==k){
			for(int j=1;j<=tot;++j){
				ans=max(ans,dp[j][i]);
			}
		}
	}
	return ans;
}
int main(){
	n=read(),tot=1;
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		int x=read();
		Insert(s,x);
	}
	init();
	scanf("%s",s+1);
	printf("%lld\n",Solve(s));
	return 0;
}