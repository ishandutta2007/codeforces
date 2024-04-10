#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int B=250;
int p1=5000000,p2=0;
char buf[5000005],wbuf[5000005];
int gc(){
	if(p1>=5000000)fread(buf,1,5000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0,ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))x=x*10+ch-'0',ch=gc();
	return x;
}
struct T{
	int x,id;
}tmp[100005];
int bx[100005],bid[100005],cx[100005],cid[100005],nowans[100005];
int a[100005],pre[100005],bel[100005],S[100005],E[100005],dfn[100005],tag[100005];
int size[100005],son[100005],n,m,fa[100005],is[100005],top[100005],sign,sum=1,ts=0;
vector<int> g[100005];
const bool operator <(const T i,const T j){
	return i.x<j.x;
}
void dfs(int x){
	size[x]=1;
	for(int y:g[x]){
		dfs(y),size[x]+=size[y];
		if(size[y]>size[son[x]])son[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp,dfn[x]=++sign;
	if(son[x])dfs2(son[x],tp);
	else {
		int l=dfn[top[x]],r=dfn[x],t=100;
		if(r-l<10){
			for(int i=l;i<=r;i++)bel[i]=sum;
			if(r-ts>=250)sum++,ts=r;
			return ;
		}
		if(sqrt(r-l+1)>=t)t=sqrt(r-l+1),t=min(t,250);
		for(int i=l;i<=r;i++)bel[i]=(i-l)/t+sum;
		sum=bel[r]+1,ts=r;
	}
	for(int y:g[x])if(y^son[x])dfs2(y,y);
}
void Make(int x){
	for(int s=S[bel[x]],e=E[bel[x]],i=s;i<=e;i++){
		if(bid[i]==x){
			int dlt=1-2*is[x];
			while(i<=e)pre[i]+=dlt,i++;
		}
	}
	is[x]^=1;
}
void Addb(int p,int l,int r,int x){
	int tc=0,s=S[p],e=E[p];
	for(int i=s;i<=e;i++)bx[i]+=tag[p];
	tag[p]=0,nowans[p]=-1;
	int L=s,R=e;
	while(bid[L]<l||bid[L]>r)L++;
	while(bid[R]<l||bid[R]>r)R--;
	while(L>s&&bx[L-1]==bx[L])L--;
	while(R<e&&bx[R+1]==bx[R])R++;
	for(int i=L,j;i<=R;i=j+1){
		j=i;
		while(j<R&&bx[j+1]==bx[i])j++;
		if(x==1){
			for(int k=i;k<=j;k++)if(bid[k]<l||bid[k]>r)cid[++tc]=bid[k],cx[tc]=bx[k];
			for(int k=i;k<=j;k++)if(bid[k]>=l&&bid[k]<=r)cid[++tc]=bid[k],cx[tc]=bx[k]+1;//puts("PP");
		}
		else {
			for(int k=i;k<=j;k++)if(bid[k]>=l&&bid[k]<=r)cid[++tc]=bid[k],cx[tc]=bx[k]-1;//puts("PP");
			for(int k=i;k<=j;k++)if(bid[k]<l||bid[k]>r)cid[++tc]=bid[k],cx[tc]=bx[k];
		}
	}
	for(int i=L;i<=R;i++)bx[i]=cx[i-L+1],bid[i]=cid[i-L+1];
	for(int i=L;i<=e;i++)pre[i]=(i==s?0:pre[i-1])+is[bid[i]];
}
void Add(int l,int r,int x){
	Addb(bel[l],l,r,x);
	if(bel[l]==bel[r])return ;
	Addb(bel[r],l,r,x);
	for(int i=bel[l]+1;i<bel[r];i++)tag[i]+=x,nowans[i]=-1;
}
int Query(){
	int ans=0;
	for(int i=1;i<=bel[n];i++){
		if(nowans[i]!=-1){
			ans+=nowans[i];
			continue;
		}
		int pos=lower_bound(bx+S[i],bx+E[i]+1,-tag[i])-bx-1;
		if(pos>=S[i])ans+=pre[pos],nowans[i]=pre[pos];
		else nowans[i]=0;
	}
	return ans;
}
void Upd(int x){
	int p=dfn[x];
	while(x)Add(dfn[top[x]],dfn[x],1-2*is[p]),x=fa[top[x]];
	Make(p);
}
int main(){
	n=rd(),m=rd();
	for(int i=2,x;i<=n;i++)x=rd(),fa[i]=x,g[x].push_back(i);
	dfs(1),dfs2(1,1);
	for(int i=1;i<=n;i++)a[i]=rd(),is[i]=1,tmp[dfn[i]]={a[i],dfn[i]};
	for(int i=1;i<=n;i++)E[bel[i]]=i;
	for(int i=n;i>=1;i--)S[bel[i]]=i;
	for(int i=1;i<=bel[n];i++){
		nowans[i]=-1;
		int s=S[i],e=E[i];
		sort(tmp+s,tmp+e+1);
		for(int j=s;j<=e;j++)pre[j]=j-s+1,bx[j]=tmp[j].x,bid[j]=tmp[j].id;
	}
	while(m--){
		int x=rd();
		Upd(x);
		printf("%d ",Query());
	}
}