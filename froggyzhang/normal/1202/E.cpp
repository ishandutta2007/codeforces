#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
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
struct AC{
	int cnt;
	AC(){cnt=1;}
	struct node{
		int fa,nxt,ed,ch[26];
	}trie[N];
	void Insert(string &s){
		int u=1;
		for(int i=0;i<(int)s.length();++i){
			int c=s[i]-'a';
			if(!trie[u].ch[c])trie[u].ch[c]=++cnt;
			u=trie[u].ch[c];
		}	
		++trie[u].ed;
	}
	void build(){
		for(int c=0;c<26;++c){
			trie[0].ch[c]=1;
		}
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int c=0;c<26;++c){
				int v=trie[u].ch[c];
				if(v){
					trie[v].nxt=trie[trie[u].nxt].ch[c];
					q.push(v);
				}
				else trie[u].ch[c]=trie[trie[u].nxt].ch[c];
			}
			trie[u].ed+=trie[trie[u].nxt].ed;
		}
	}
	void Run(char *s,int len,int *f){
		int u=1;
		for(int i=1;i<=len;++i){
			int c=s[i]-'a';
			u=trie[u].ch[c];
			f[i]=trie[u].ed;
		}	
	}
}A1,A2;
int n,len,f[N],g[N];
char t[N];
string s;
ll ans;
int main(){
	scanf("%s",t+1);
	len=strlen(t+1);
	n=read();
	for(int i=1;i<=n;++i){
		cin>>s;
		A1.Insert(s);
		reverse(s.begin(),s.end());
		A2.Insert(s);
	}
	A1.build();
	A2.build();
	A1.Run(t,len,f);
	reverse(t+1,t+len+1);
	A2.Run(t,len,g);
	for(int i=1;i<len;++i){
		ans+=1LL*f[i]*g[len-i];
	}
	printf("%lld\n",ans);
	return 0;
}