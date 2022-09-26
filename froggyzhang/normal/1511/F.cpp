/*qwq*/
#include<bits/stdc++.h>
using namespace std;
#define N 320
typedef long long ll;
const int mod=998244353;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
char s[10];
struct Trie{
	struct node{
		int ch[26];
		bitset<26> ed;
		node(){ed.reset();}
	}trie[N];
	int tot;
	Trie(){tot=1;}
	void Insert(char *s){
		int len=strlen(s+1);
		int u=1;
		for(int i=1;i<len;++i){
			int c=s[i]-'a';
			if(!trie[u].ch[c])trie[u].ch[c]=++tot;
			u=trie[u].ch[c];
		}
		trie[u].ed[s[len]-'a']=1;
	}
}T;
int cnt;
struct Matrix{
	int g[N][N];
	Matrix(){memset(g,0,sizeof(g));}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix c;
		for(int i=1;i<=cnt;++i){
			for(int j=1;j<=cnt;++j){
				for(int k=1;k<=cnt;++k){
					c.g[i][j]=(c.g[i][j]+1LL*a.g[i][k]*b.g[k][j])%mod;
				}
			}
		}	
		return c;
	}
}A,pre,e;
map<pair<int,int>,int> mp;
Matrix mpow(Matrix a,int b){
	Matrix ans=e;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;	
}
queue<pair<int,int> > q;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		T.Insert(s);
	}
	mp[make_pair(1,1)]=++cnt;
	q.push(make_pair(1,1));
	while(!q.empty()){
		auto [u1,u2]=q.front();
		q.pop();
		for(int i=0;i<26;++i){
			for(int p1=0;p1<=1;++p1){
				for(int p2=0;p2<=1;++p2){
					if(p1&&!T.trie[u1].ed[i])continue;
					if(p2&&!T.trie[u2].ed[i])continue;
					int v1=p1?1:T.trie[u1].ch[i];
					int v2=p2?1:T.trie[u2].ch[i];
					if(!v1||!v2)continue;
					if(!mp.count(make_pair(v1,v2))){
						mp[make_pair(v1,v2)]=++cnt;
						q.push(make_pair(v1,v2));
					}
					A.g[mp[make_pair(v1,v2)]][mp[make_pair(u1,u2)]]++;
				}
			}	
		}	
	}
	for(int i=1;i<=cnt;++i)e.g[i][i]=1;
	pre.g[1][mp[make_pair(1,1)]]=1;
	Matrix ans=pre*mpow(A,m);
	printf("%d\n",ans.g[1][1]);
	return 0;
}