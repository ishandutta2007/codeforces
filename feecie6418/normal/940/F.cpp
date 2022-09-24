#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],t[200005],bel[200005],n,m,qnum,cnum,ans[200005],s[200005],o[200005];
int nowl,nowr,nowt;
struct Query{
	int l,r,t,id;
	bool operator <(const Query yy) const {
		return bel[l]==bel[yy.l]?(bel[r]==bel[yy.r]?t<yy.t:bel[r]<bel[yy.r]):bel[l]<bel[yy.l];
	}
}q[200005];
struct Change{
	int pos,pre,now;
}c[200005];
int Q(){
	for(int i=1;;i++)if(!o[i])return i;
}
void Add(int x){
	--o[s[x]],o[++s[x]]++;
}
void Del(int x){
	--o[s[x]],o[--s[x]]++;
}
void Update(int x){
	if(nowl<=c[x].pos&&c[x].pos<=nowr)Del(c[x].pre),a[c[x].pos]=c[x].now,Add(c[x].now);
	else a[c[x].pos]=c[x].now;
}
void Reduct(int x){
	if(nowl<=c[x].pos&&c[x].pos<=nowr)Del(c[x].now),a[c[x].pos]=c[x].pre,Add(c[x].pre);
	else a[c[x].pos]=c[x].pre;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,blk=pow(n,0.67);i<=n;i++)scanf("%d",&a[i]),t[++t[0]]=a[i],b[i]=a[i],bel[i]=i/blk+1;
	for(int i=1,opt,x,y;i<=m;i++){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)++qnum,q[qnum]=(Query){x,y,cnum,qnum};
		else c[++cnum]=(Change){x,b[x],y},b[x]=y,t[++t[0]]=y;
	}
	sort(t+1,t+t[0]+1);
	for(int i=1;i<=cnum;i++)c[i].now=lower_bound(t+1,t+t[0]+1,c[i].now)-t,c[i].pre=lower_bound(t+1,t+t[0]+1,c[i].pre)-t;
	for(int i=1;i<=n;i++)a[i]=lower_bound(t+1,t+t[0]+1,a[i])-t;
	sort(q+1,q+qnum+1);
	nowl=1,nowr=0,nowt=0;
	for(int i=1;i<=qnum;i++){
		while(nowl>q[i].l)Add(a[--nowl]);
		while(nowr<q[i].r)Add(a[++nowr]);
		while(nowl<q[i].l)Del(a[nowl++]);
		while(nowr>q[i].r)Del(a[nowr--]);
		while(nowt<q[i].t)Update(++nowt);
		while(nowt>q[i].t)Reduct(nowt--);
		ans[q[i].id]=Q();
	}
	for(int i=1;i<=qnum;i++)printf("%d\n",ans[i]);
}//