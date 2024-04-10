#include <bits/stdc++.h>
using namespace std;
int n,m,f[500005],isfir[500005],low[500005],dfn[500005],sign,st[500005],A[500005];
int tmp[500005],top,sl,bel[500005],pr[500005],sf[500005],h[500005],W[500005];
int f1[21][500005],f2[21][500005],lg2[500005];
vector<int> G[500005],loop[500005],g[500005];
void dfs1(int x,int fr){
	dfn[x]=low[x]=++sign,st[++top]=x;
	for(int y:G[x]){
		if(!dfn[y])dfs1(y,x),low[x]=min(low[x],low[y]);
		else if(y^fr)low[x]=min(low[x],dfn[y]);
	}
	if(low[x]!=dfn[x])return ;
	isfir[x]=1,sl++;
	int tmp;
	do {
		tmp=st[top--],loop[sl].push_back(tmp);
		if(tmp^x)g[x].push_back(tmp);
		bel[tmp]=sl;
	} while(tmp!=x);
}
void dfs2(int x){
	for(int y:g[x]){
		dfs2(y);
		if(!isfir[x]||loop[bel[x]].size()==1||bel[x]!=bel[y])f[x]=max(f[x],f[y]+1);
	}
	if(!isfir[x]||loop[bel[x]].size()==1)return /*cout<<x<<' '<<f[x]<<' '<<bel[x]<<'\n',void()*/;
	int ts=0,mn=1e9;
	for(int i:loop[bel[x]])if(i!=x)tmp[++ts]=i;
	// a[i],a[i-1] max(f[a[j]]+j(j<i),f[a[j]]+ts+1-j(j>=i))
	pr[0]=sf[ts+1]=-1e9; 
	for(int i=1;i<=ts;i++)pr[i]=max(pr[i-1],f[tmp[i]]+i);
	for(int i=ts;i>=1;i--)sf[i]=max(sf[i+1],f[tmp[i]]-i);
	for(int i=1;i<=ts+1;i++)mn=min(mn,max(pr[i-1],sf[i]+ts+1));
	f[x]=max(f[x],mn);
	A[x]=mn;
}
int Q1(int l,int r){
	if(l>r)return -1e9;
	int k=lg2[r-l+1];
	return max(f1[k][l],f1[k][r-(1<<k)+1]);
}
int Q2(int l,int r){
	if(l>r)return -1e9;
	int k=lg2[r-l+1];
	return max(f2[k][l],f2[k][r-(1<<k)+1]);
}
int pre,suf;
int Find(int i,int ts,int mid){
	pre=-1e9,suf=-1e9;
	if(mid>1)pre=max(pre,Q1(i+1,min(i+mid-1,ts))-i);
	if(i+mid-1>ts)pre=max(pre,Q1(1,i+mid-1-ts)+ts-i);
	if(i+mid<=ts)suf=max(suf,Q2(i+mid,ts)+i+ts);
	if(mid<ts)suf=max(suf,Q2(max(1,i+mid-ts),i-1)+i);
	return max(pre,suf);
}
int p1=2000000,p2=0;
char buf[2000005],wbuf[2000005];
int gc(){
	if(p1>=2000000)fread(buf,1,2000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0,ff=1;
	char ch=gc();
	while((ch<'0'||ch>'9')&&ch!='-')ch=gc();
	if(ch=='-')ff=-1,ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x*ff;
}
void pc(char x){
	if(p2==2000000)fwrite(wbuf,1,p2,stdout),p2=0;
	wbuf[p2++]=x;
}
void wrt(int x){
	if(x<0)return pc('-'),wrt(-x);
	if(!x)return pc('0');
	int t[20]={0};
	while(x)t[++t[0]]=x%10,x/=10;
	while(t[0])pc(t[t[0]--]+'0');
}
void dfs3(int x){
	int ts=0;
	for(int y:g[x])if(bel[y]!=bel[x])tmp[++ts]=y;
	pr[0]=sf[ts+1]=-1e9;
	for(int i=1;i<=ts;i++)pr[i]=max(pr[i-1],f[tmp[i]]+1);
	for(int i=ts;i>=1;i--)sf[i]=max(sf[i+1],f[tmp[i]]+1);
	for(int i=1;i<=ts;i++)h[tmp[i]]=max(max(pr[i-1],sf[i+1]),max(h[x],A[x]))+1;
	int w=max(h[x],pr[ts]);
	for(int y:g[x])if(bel[y]!=bel[x])dfs3(y);
	if(!isfir[x]||loop[bel[x]].size()==1)return ;
	ts=0;
	for(int i:loop[bel[x]])tmp[++ts]=i,W[ts]=(i==x?w:f[i]);
	for(int i=1;i<=ts;i++)f1[0][i]=W[i]+i,f2[0][i]=W[i]-i;
	for(int i=1;i<=18;i++)for(int j=1;j+(1<<i)-1<=ts;j++)f1[i][j]=max(f1[i-1][j],f1[i-1][j+(1<<i-1)]),f2[i][j]=max(f2[i-1][j],f2[i-1][j+(1<<i-1)]);
	for(int i=1;i<=ts;i++){
		if(tmp[i]==x)continue;
		//ts
		//jtmp[i]jtmp[(i+j-1)%ts+1]tmp[(i+j)%ts+1]
		//pre<suf()
		int l=1,r=ts,ans=1;
		while(l<=r){
			int mid=(l+r)/2;//i+1~i+mid-1:pre
			Find(i,ts,mid);
			if(pre<suf)ans=mid,l=mid+1;
			else r=mid-1;
		}
		h[tmp[i]]=max(h[tmp[i]],min(Find(i,ts,ans),Find(i,ts,ans+1)));
	}
	for(int y:g[x])if(bel[y]==bel[x])dfs3(y);
}
int main(){
	lg2[0]=-1,n=rd(),m=rd();
	for(int i=1,x,y;i<=m;i++)x=rd(),y=rd(),G[x].push_back(y),G[y].push_back(x);
	for(int i=1;i<=n;i++)lg2[i]=lg2[i>>1]+1;
	dfs1(1,0);
	for(int j=1;j<=n;j++){
		for(int k:G[j]){
			if(bel[j]>bel[k])g[j].push_back(k);
		}
	}
	dfs2(1),dfs3(1);
	for(int i=1;i<=n;i++)wrt(max(f[i],h[i])),pc(' ');
	fwrite(wbuf,1,p2,stdout);
}