#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int Max[N<<2],las,Siz=1,dfn[N],siz[N],id[N],dfns;
struct node {
	int len,link,to[26];
} st[N<<1];
vector<int>S[N];
void ins(int c) {
	int p=las,now=Siz++;
	st[now].len=st[las].len+1;
	id[st[now].len]=now;
	while(~p&&!st[p].to[c]) {
		st[p].to[c]=now;
		p=st[p].link;
	}
	if(~p) {
		int q=st[p].to[c];
		if(st[p].len+1==st[q].len)st[now].link=q;
		else {
			int cpy=Siz++;
			st[cpy]=st[q];
			st[cpy].len=st[p].len+1;
			while(~p&&st[p].to[c]==q) {
				st[p].to[c]=cpy;
				p=st[p].link;
			}
			st[q].link=st[now].link=cpy;
		}
	}
	las=now;
}
char s[N];
void dfs(int x) {
	dfn[x]=++dfns;
	siz[x]=1;
	// cerr<<dfn[x]<<' '<<x<<endl;
	for(int y:S[x]) {
		// cerr<<x<<' '<<y<<endl;
		dfs(y);
		siz[x]+=siz[y];
	}
}
struct Node{
	int l,r,id;
	string S;
	int operator<(const Node &a)const {
		return r<a.r;
	}
}q[N];
int cmp(int a,int b) {
	return st[a].len<st[b].len;
}
void add(int p,int l,int r,int x,int v) {
	Max[p]=max(Max[p],v);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,v);
	else add(p<<1|1,mid+1,r,x,v);
}
int qry(int p,int l,int r,int x,int y) {
	// if(p==1)cerr<<x<<' '<<y<<endl;
	if(x<=l&&r<=y)return Max[p];
	int mid=(l+r)>>1,ans=0;
	if(x<=mid)ans=max(ans,qry(p<<1,l,mid,x,y));
	if(y>mid)ans=max(ans,qry(p<<1|1,mid+1,r,x,y));
	return ans;
}
int check(int p,int R) {
	if(p<=0)return 0;
	// cerr<<qry(1,1,Siz,dfn[p],dfn[p]+siz[p]-1)<<' '<<R<<endl;
	// cerr<<p<<' '<<st[p].len<<' '<<dfn[p]<<' '<<siz[p]<<endl;
	return qry(1,1,Siz,dfn[p],dfn[p]+siz[p]-1)>=R;
}
string ans[N];
int main() {
	st[0].link=-1;
	scanf("%s",s+1);
	int n=strlen(s+1),m;
	for(int i=1; i<=n; i++)
		ins(s[i]-'a');
	for(int i=1; i<Siz; i++)
		S[st[i].link].push_back(i);
	dfs(0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		cin>>q[i].l>>q[i].r>>q[i].S;
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	// cerr<<"OK"<<endl;
	for(int i=1,j=1;i<=m;i++) {
		// cerr<<q[i].r<<' '<<q[i].l<<' '<<q[i].S<<endl;
		while(j<=q[i].r) {
			// if(pos[j]==2)cerr<<"OK"<<' '<<dfn[pos[j]]<<endl;
			add(1,1,Siz,dfn[id[j]],j);
			j++;
		}
		int p=0,len=-1,c=0;
		for(int j=0;j<(int)q[i].S.size();j++) {
			int v=q[i].S[j]-'a';
			for(int k=v+1;k<26;k++)
				if(check(st[p].to[k],q[i].l+j)) {
					len=j;
					c=k;
					break;
				}
			p=st[p].to[v];
			// cerr<<p<<endl;
			if(!p)break;
		}
		if(p) {
			for(int k=0;k<26;k++) {
				if(check(st[p].to[k],q[i].l+q[i].S.size())) {
					len=q[i].S.size();
					c=k;
					break;
				}
			}
		}
		// cerr<<q[i].id<<endl;
		if(len==-1)ans[q[i].id]="-1";
		else {
			for(int j=0;j<len;j++)
				ans[q[i].id].push_back(q[i].S[j]);
			ans[q[i].id].push_back(c+'a');
			if(ans[q[i].id]<=q[i].S)return -1;
		}
		// cerr<<ans[i]<<endl;
		// cerr<<endl;
	}
	// return 0;
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}