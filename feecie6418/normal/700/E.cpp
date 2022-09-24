#include<bits/stdc++.h>
using namespace std;
const int A=400005;
char str[A];
int lens,ls[A*40],rs[A*40],s[A*40],root[A],tot;
typedef long long ll;
void Insert(int &p,int l,int r,int x){
	p=++tot,s[p]=1;
	if(l==r)return ;
	int mid=(l+r)/2;
	if(x<=mid)Insert(ls[p],l,mid,x);
	else Insert(rs[p],mid+1,r,x);
}
int Merge(int p,int q,int l,int r){
	if(!p||!q)return p+q;
	if(l>r)return 0;
	int rr=++tot,mid=(l+r)/2;
	ls[rr]=Merge(ls[p],ls[q],l,mid),rs[rr]=Merge(rs[p],rs[q],mid+1,r);
	s[rr]=s[ls[rr]]+s[rs[rr]];
	return rr;
}
int Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return s[p];
	int mid=(l+r)/2,ret=0;
	if(x<=mid)ret+=Query(ls[p],l,mid,x,y);
	if(mid<y)ret+=Query(rs[p],mid+1,r,x,y);
	return ret;
}
struct SAM {
	int c[A][26],fa[A],len[A],lst=1,tot=1,w[A],rk[A],s[A],f[A],fr[A],mx[A];
	void Ins(int x,int ww) {
		int p=lst,now=++tot;
		memset(c[now],0,sizeof(c[now])),lst=now,w[now]=ww;
		len[now]=len[p]+1;
		for(; p&&!c[p][x]; p=fa[p])c[p][x]=now;
		if(!p)return fa[now]=1,void();
		int q=c[p][x];
		if(len[p]+1==len[q])return fa[now]=q,void();
		int nq=++tot;
		memcpy(c[nq],c[q],sizeof(c[q])),len[nq]=len[p]+1,fa[nq]=fa[q],fa[now]=fa[q]=nq;
		for(; p&&c[p][x]==q; p=fa[p])c[p][x]=nq;
	}
	void Make(){
		for(int i=1;i<=tot;i++)s[len[i]]++;
		for(int i=1;i<=tot;i++)s[i]+=s[i-1];
		for(int i=1;i<=tot;i++)if(w[i])Insert(root[i],1,lens,w[i]),mx[i]=w[i];
		for(int i=tot;i>=1;i--)rk[s[len[i]]--]=i;
		for(int i=tot,x;i>=1;i--)if(fa[x=rk[i]])root[fa[x]]=Merge(root[fa[x]],root[x],1,lens),mx[fa[x]]=max(mx[fa[x]],mx[x]);
		int ans=0;
		for(int i=2,x,y;i<=tot;i++){
			x=rk[i],y=fa[x];
			if(y==1)f[x]=1,fr[x]=x;
			else if(Query(root[fr[y]],1,lens,mx[x]-len[x]+len[fr[y]],mx[x]-1))fr[x]=x,f[x]=f[fr[y]]+1;
			else fr[x]=fr[y],f[x]=f[y];
			ans=max(ans,f[x]);
		}
		cout<<ans;
	}
}S;
int main() {
	scanf("%d%s",&lens,str);
	for(int i=0;i<lens;i++)S.Ins(str[i]-'a',i+1);
	S.Make();
}