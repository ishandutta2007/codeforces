#include<bits/stdc++.h>
using namespace std;
#define N 600060
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
int Q;
char s[N];
struct AC{
	int tot=0;
	struct node{
		int ch[26],nxt,val,sum,to[26];
	}trie[N];
	void Insert(char *s,int rt){
		int len=strlen(s+1);
		int u=rt;
		for(int i=1;i<=len;++i){
			int c=s[i]-'a';
			if(!trie[u].ch[c])trie[u].ch[c]=++tot;
			u=trie[u].ch[c];
		}
		++trie[u].val;
	}
	int Merge(int l,int r){
		if(!l||!r)return l|r;
		trie[l].val+=trie[r].val;
		for(int c=0;c<26;++c){
			trie[l].ch[c]=Merge(trie[l].ch[c],trie[r].ch[c]);
		}
		return l;
	}
	void build(int rt){
		queue<int> q;
		for(int c=0;c<26;++c)trie[0].to[c]=rt;
		q.push(rt);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int c=0;c<26;++c){
				int v=trie[u].ch[c];
				if(v){
					trie[u].to[c]=trie[u].ch[c];
					trie[v].nxt=trie[trie[u].nxt].to[c];
					q.push(v);
				}
				else trie[u].to[c]=trie[trie[u].nxt].to[c];
			}
			trie[u].sum=trie[u].val+trie[trie[u].nxt].sum;
		}
	}
	pair<int,int> st[N];
	int top;
	void Add(char *s){
		int rt;
		st[++top].first=rt=++tot;
		st[top].second=1;
		Insert(s,tot);
		while(top>1&&st[top-1].second==st[top].second){
			st[top-1].first=Merge(st[top-1].first,st[top].first);
			st[top-1].second<<=1;
			--top;
		}
		build(st[top].first);
	}
	int Query(char *s){
		int ans=0,len=strlen(s+1);
		for(int i=1;i<=top;++i){
			int u=st[i].first;
			for(int j=1;j<=len;++j){
				int c=s[j]-'a';
				u=trie[u].to[c];
				if(!u)break;
				ans+=trie[u].sum;
			}
		}
		return ans;
	}
}A,B;
int main(){
	Q=read();
	while(Q--){
		int opt=read();
		scanf("%s",s+1);
		if(opt==1){
			A.Add(s);
		}
		else if(opt==2){
			B.Add(s);
		}
		else{
			printf("%d\n",A.Query(s)-B.Query(s));
			fflush(stdout);
		}
	}
	return 0;
}