
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pr;
int n,m,c[1000005][2],fa[1000005],rev[1000005],st[1000005],top,is[1000005],has[1000005],X[1000005],Y[1000005];
set<pr> s;
map<pr,bool> mp;
bool isroot(int x){
	return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
}
void Pushdown(int x){
	if(rev[x]){
		swap(c[x][0],c[x][1]);
		rev[c[x][0]]^=1,rev[c[x][1]]^=1;
		rev[x]=0;
	}
}
void Pushup(int x){
	if(is[x])has[x]=x;
	else if(has[c[x][0]])has[x]=has[c[x][0]];
	else has[x]=has[c[x][1]];
}
void Rotate(int x){
	int y=fa[x],z=fa[y],l=c[y][0]!=x,r=!l;
	if(!isroot(y)){
		if(c[z][0]==y)c[z][0]=x;
		else c[z][1]=x;
	}
	fa[x]=z,fa[y]=x,fa[c[x][r]]=y;
	c[y][l]=c[x][r],c[x][r]=y;
	Pushup(y),Pushup(x);
}
void Splay(int x){
	st[top=1]=x;
	int y=x;
	while(!isroot(y))y=fa[y],st[++top]=y;
	for(int i=top; i>=1; i--)Pushdown(st[i]);
	while(!isroot(x)){
		int y=fa[x],z=fa[y];
		if(!isroot(y)){
			if((c[y][0]==x)!=(c[z][0]==y))Rotate(x);
			else Rotate(y);
		}
		Rotate(x);
	}
}
void Access(int x){
	for(int y=0;x;y=x,x=fa[x])Splay(x),c[x][1]=y,Pushup(x);
}
void Makeroot(int x){
	Access(x),Splay(x),rev[x]^=1;
}
void Link(int x,int y){
	Makeroot(x),fa[x]=y;
}
void Split(int x,int y){
	Makeroot(x),Access(y),Splay(y);
}
void Cut(int x,int y){
	Split(x,y);
	if(c[y][0]==x)c[y][0]=0,fa[x]=0,Pushup(y);
}
int main(){
	scanf("%d",&n);
	int ans=n-1;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),X[i]=x,Y[i]=y,s.insert(pr(x,y)),s.insert(pr(y,x));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),X[i+n]=x,Y[i+n]=y,mp[pr(x,y)]=1,mp[pr(y,x)]=1,ans-=s.count(pr(x,y));
	cout<<ans<<'\n';
	for(int i=1;i<n;i++){
		if(!mp[pr(X[i],Y[i])])is[i+n]=1;
		Link(X[i],i+n),Link(Y[i],i+n);
	}
	for(int i=1;i<n;i++){
		int x=X[i+n],y=Y[i+n];
		if(s.count(pr(x,y)))continue;
		Split(x,y);
		int u=has[y];
		int z=X[u-n],w=Y[u-n];
		Cut(z,u),Cut(w,u);
		Link(x,y),printf("%d %d %d %d\n",z,w,x,y);
	}
}