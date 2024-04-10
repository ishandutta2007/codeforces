#include<bits/stdc++.h>
using namespace std;
struct Query{
	int opt,x,y;//1,add 2,find 3,remove
}q[200005];
struct P{
	int x,y;
	bool operator <(const P p) const {
		return x!=p.x?x<p.x:y<p.y;
	}
};
int b[400005],n;
set<P> c[400005];
void Upd(int t,int x,int y){
	while(t<=b[0])c[t].insert({x,y}),t+=t&-t;
}
void Rem(int t,int x,int y){
	while(t<=b[0])c[t].erase({x,y}),t+=t&-t;
}
P Find(int t,int x,int y){
	P ret={1<<30,1<<30};
	while(t)ret=min(ret,*(c[t].lower_bound({x+1,y+1}))),t-=t&-t;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		char o[8];
		scanf("%s%d%d",o,&x,&y),b[++b[0]]=y;
		q[i]={(o[0]=='a'?1:(o[0]=='f'?2:3)),x,y};
	}
	sort(b+1,b+b[0]+1);
	for(int i=1;i<=b[0];i++)c[i].insert({1<<30,1<<30});
	for(int i=1;i<=n;i++){
		q[i].y=lower_bound(b+1,b+b[0]+1,q[i].y)-b;
		if(q[i].opt==1)Upd(b[0]-q[i].y+1,q[i].x,q[i].y);
		if(q[i].opt==2){
			P o=Find(b[0]-q[i].y,q[i].x,q[i].y);
			if(o.y==(1<<30))puts("-1");
			else cout<<o.x<<' '<<b[o.y]<<'\n';
		}
		if(q[i].opt==3)Rem(b[0]-q[i].y+1,q[i].x,q[i].y);
	}
}