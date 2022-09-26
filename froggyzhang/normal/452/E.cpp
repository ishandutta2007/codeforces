#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define N 600300 
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
char s[N];
int las,tot,mn,d[N][3];
ll ans[N];
struct SAM{
	int ch[26],fa,len;
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
		d[u][2]+=d[v][2];
	}
	ll tmp=1LL*d[u][0]*d[u][1]*d[u][2]%mod;
	ans[t[t[u].fa].len+1]=(ans[t[t[u].fa].len+1]+tmp)%mod;
	ans[t[u].len+1]=(ans[t[u].len+1]-tmp+mod)%mod;
}
int main(){
	tot=1;mn=23333333;
	for(int i=1;i<=3;++i){
		scanf("%s",s+1);
		las=1;
		int n=strlen(s+1);
		mn=min(n,mn);
		for(int j=1;j<=n;++j){
			Insert(s[j]-'a',i-1);
		}
	}
	for(int i=2;i<=tot;++i){
		add(t[i].fa,i);
	}
	dfs(1);
	for(int i=1;i<=mn;++i){
		ans[i]=(ans[i]+ans[i-1])%mod;
		printf("%I64d ",ans[i]);
	}
	return 0;
}