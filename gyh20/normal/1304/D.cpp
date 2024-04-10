#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
	t=(t<<3)+(t<<1)+v-48;
	v=getchar();}
	return t;
}
map<string,int>mp;
int t,n,ans[200002],k,cnt,tot,rd[200002],head[200002];
char s[200002];
struct edge{
int to,next;
}e[200002]; 
inline void add(re int x,re int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
struct node{
	int pos;
	bool operator <(const node &x)const{
		return x.pos>pos;
	}
};
struct node1{
	int pos;
	bool operator <(const node1 &x)const{
		return x.pos<pos;
	}
};
priority_queue <node> q;
priority_queue <node1> q1;
int main(){
t=read();
while(t--){
	n=read();scanf("%s",s+1);
	memset(rd,0,sizeof(rd));
	tot=0;
	cnt=0;
	memset(head,0,sizeof(head));
	for(re int i=1;i<n;++i){
		if(s[i]=='>')add(i+1,i),++rd[i];
		else add(i,i+1),++rd[i+1];
	}
	for(re int i=1;i<=n;++i){
		if(rd[i]==0)q.push(node{i});
	}
	while(!q.empty()){
		int x=q.top().pos;
		q.pop();
		ans[x]=++tot;
		for(re int i=head[x];i;i=e[i].next){
			--rd[e[i].to];
			if(!rd[e[i].to])q.push(node{e[i].to});
		}
	}
	for(re int i=1;i<=n;++i)printf("%d ",ans[i]);putchar('\n');
	memset(rd,0,sizeof(rd));
	tot=0;
	cnt=0;
	memset(head,0,sizeof(head));
	for(re int i=1;i<n;++i){
		if(s[i]=='>')add(i+1,i),++rd[i];
		else add(i,i+1),++rd[i+1];
	}
	for(re int i=1;i<=n;++i){
		if(rd[i]==0)q1.push(node1{i});
	}
	while(!q1.empty()){
		int x=q1.top().pos;
		q1.pop();
		ans[x]=++tot;
		for(re int i=head[x];i;i=e[i].next){
			--rd[e[i].to];
			if(!rd[e[i].to])q1.push(node1{e[i].to});
		}
	}
	for(re int i=1;i<=n;++i)printf("%d ",ans[i]);putchar('\n');
}
}