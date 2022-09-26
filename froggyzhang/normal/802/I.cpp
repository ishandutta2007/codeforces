#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 200010
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
int n,T,las,tot,d[N];
ll ans;
char s[N];
struct SAM{
	int fa,ch[26],len;
}t[N];
int head[N],cnt;
struct Edge{
	int to,nxt;
}edge[N];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void Insert(int c){
	int u=++tot;
	++d[u];
	t[u].len=t[las].len+1;
	int p=las;
	while(p&&!t[p].ch[c]){
		t[p].ch[c]=u;
		p=t[p].fa;
	} 
	if(!p){
		t[u].fa=1;
	}
	else{
		int q=t[p].ch[c];
		if(t[q].len==t[p].len+1){
			t[u].fa=q;
		}
		else{
			int clone=++tot;
			t[clone]=t[q];
			t[clone].len=t[p].len+1;
			while(p&&t[p].ch[c]==q){
				t[p].ch[c]=clone;
				p=t[p].fa;
			}
			t[u].fa=t[q].fa=clone;
		}
	}
	las=u;
}
void dfs(int u){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		dfs(v);
		d[u]+=d[v];
	}
	ans+=1LL*d[u]*d[u]*(t[u].len-t[t[u].fa].len);
}
void Solve(){
	las=tot=1;cnt=ans=0;
	memset(t,0,sizeof(t));
	memset(d,0,sizeof(d));
	memset(head,0,sizeof(head));
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		Insert(s[i]-'a');
	}
	for(int i=2;i<=tot;++i){
		add(t[i].fa,i);
	}
	dfs(1);
	printf("%I64d\n",ans);
}
int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		Solve();
	}
	return 0;
}