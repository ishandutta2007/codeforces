#include<bits/stdc++.h>
using namespace std;
const int B=3;
int n,h[300005],fa[300005],cnt,mch[300005],tp[300005],vst[300005],pre[300005],sign,tot;
int a[300005],is[300005],ans=0,id[300005],cc[300005][2],b[300005],idc[300005];
queue<int> q;
struct Edge{
	int to,next;
}e[300005];
void Add(int x,int y){
	e[++cnt]=(Edge){y,h[x]};
	h[x]=cnt;
	e[++cnt]=(Edge){x,h[y]};
	h[y]=cnt;
}
int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int LCA(int x,int y){
	++sign,x=gf(x),y=gf(y);
	while(1){
		if(x){
			if(vst[x]==sign)return x;
			vst[x]=sign;
			x=gf(pre[mch[x]]);
		}
		swap(x,y);
	}
}
void Shrink(int x,int y,int lca){
	while(gf(x)^lca){
		pre[x]=y,y=mch[x];
		if(tp[y]==1)tp[y]=0,q.push(y);
		fa[x]=fa[y]=lca,x=pre[y];
	}
}
int BFS(int x){
	for(int i=1;i<=tot;i++)fa[i]=i,tp[i]=-1,pre[i]=0;
	while(q.size())q.pop();
	q.push(x),tp[x]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=h[now];i;i=e[i].next){
			int y=e[i].to;
			if(tp[y]==-1){
				pre[y]=now,tp[y]=1;
				if(!mch[y]){
					for(int u=y,lst,v;u;u=lst){
						v=pre[u],lst=mch[v],mch[u]=v,mch[v]=u;
					}
					return 1;
				}
				tp[mch[y]]=0,q.push(mch[y]);
			}
			else if(tp[y]==0&&gf(now)!=gf(y)){
				int lca=LCA(now,y);
				Shrink(now,y,lca),Shrink(y,now,lca);
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),b[i]=a[i];
		if(i>1&&a[i]&&a[i]==a[i-1])is[a[i]]=1;
	}
	for(int i=1;i<=n;i++)if(is[i])ans++;
	for(int i=1;i<=n;i++)if(is[a[i]])a[i]=-1;
	a[0]=a[n+1]=-1;
	for(int i=1;i<=n;i++){
		if(a[i])continue;
		int j=i;
		while(j<n&&a[j+1]==0)j++;
		if((a[i-1]==-1||cc[a[i-1]][(j-i)&1]>B)&&(a[j+1]==-1||cc[a[j+1]][(j-i)&1]>B)){
			i=j;
			continue;
		}
		if(a[i-1]!=-1)cc[a[i-1]][(j-i)&1]++;
		if(a[j+1]!=-1)cc[a[j+1]][(j-i)&1]++;
		id[i]=++tot;
		if(i!=j)id[j]=++tot;
		if(a[i-1]!=-1){
			if(!idc[a[i-1]])idc[a[i-1]]=++tot;
			Add(idc[a[i-1]],id[i]);
		}
		if(a[j+1]!=-1){
			if(!idc[a[j+1]])idc[a[j+1]]=++tot;
			Add(idc[a[j+1]],id[j]);
		}
		if(i==j)continue;
		ans+=(j-i-1)/2;
		if((j-i+1)&1){
			int x=++tot;
			Add(id[i],x),Add(id[j],x);
		}
		else {
			Add(id[i],id[j]);
		}
		i=j;
	}
	for(int i=1;i<=tot;i++)if(!mch[i])ans+=BFS(i);
	for(int i=1;i<=n;i++){
		if(a[i-1]&&a[i-1]!=-1&&a[i]==0&&mch[id[i]]==idc[a[i-1]])a[i]=a[i-1],is[a[i]]=1;
		if(a[i+1]&&a[i+1]!=-1&&a[i]==0&&mch[id[i]]==idc[a[i+1]])a[i]=a[i+1],is[a[i]]=1;
	}
	int cur=1;
	for(int i=1;i<n;i++){
		if(a[i]||a[i+1])continue;
		while(cur<=n&&is[cur])cur++;
		if(cur<=n)a[i]=a[i+1]=cur,is[cur]=1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1)cout<<b[i]<<' ';
		else if(a[i]==0)cout<<"1 ";
		else cout<<a[i]<<' ';
	}
}