#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 50050 
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
int d[11][N*20],n,m,tot,las,l[11],r[11];
char s[N];
int cc[N],aa[N*20];
ll ans;
struct node{
	int len,fa,ch[26];
}t[N*20];
void Insert(int c,int x){
	int p=las;
	if(t[p].ch[c]&&t[t[p].ch[c]].len==t[p].len+1)return (void)(++d[x][las=t[p].ch[c]]);
	int clone=0,u=0,flag=0;
	if(t[p].ch[c])u=t[p].ch[c],flag=1;
	else u=++tot,t[u].len=t[p].len+1;
	while(p&&!t[p].ch[c]){
		t[p].ch[c]=u,p=t[p].fa;
	}
	if(!p)t[u].fa=1;
	else{
		int q=t[p].ch[c];
		if(t[q].len==t[p].len+1)t[u].fa=q;
		else{
			clone=++tot;
			t[clone]=t[q];
			t[clone].len=t[p].len+1;
			while(p&&t[p].ch[c]==q){
				t[p].ch[c]=clone;
				p=t[p].fa;
			}
			t[u].fa=t[q].fa=clone;
		}
	}
	++d[x][las=(flag?clone:u)];
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	las=tot=1;
	for(int i=1;i<=n;++i){
		Insert(s[i]-'a',0);
	}
	m=read();
	for(int i=1;i<=m;++i){
		las=1;
		scanf("%s",s+1);
		int qwq=strlen(s+1);
		for(int j=1;j<=qwq;++j){
			Insert(s[j]-'a',i);
		}
		l[i]=read(),r[i]=read();
	}
	for(int i=1;i<=tot;++i)++cc[t[i].len];
	for(int i=1;i<=50000;++i)cc[i]+=cc[i-1];
	for(int i=1;i<=tot;++i)aa[cc[t[i].len]--]=i;
	for(int i=tot;i>=2;--i){
		int u=aa[i];
		bool ok=true;
		for(int j=0;j<=m;++j){
			d[j][t[u].fa]+=d[j][u];
		}
		for(int j=1;j<=m;++j){
			if(d[j][u]<l[j]||d[j][u]>r[j]){
				ok=false;break;
			}
		}
		if(ok&&d[0][u])ans+=t[u].len-t[t[u].fa].len;
	}
	printf("%I64d\n",ans);
	return 0;
}