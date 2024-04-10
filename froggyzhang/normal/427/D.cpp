#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 20020
const int inf=0x3f3f3f3f;
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
int las,tot,n,ans,d[N][2];
char s[N];
struct SAM{
	int ch[26],len,fa;
}t[N];
void Insert(int c,int x){
	int p=las;
	int u=++tot;
	++d[u][x];
	t[u].len=t[las].len+1;
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
int cnt,head[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		dfs(v);
		d[u][0]+=d[v][0];
		d[u][1]+=d[v][1];
	}
	if(u^1)if(d[u][0]==1&&d[u][1]==1)ans=min(ans,t[t[u].fa].len+1);
}
int main(){
	las=tot=1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		Insert(s[i]-'a',0);
	}
	las=1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		Insert(s[i]-'a',1);
	}
	for(int i=2;i<=tot;++i){
		add(t[i].fa,i);
	}
	ans=inf;
	dfs(1);
	printf("%d\n",ans==inf?-1:ans);
	return 0;
}