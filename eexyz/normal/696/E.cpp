#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define int long long
struct node{
	int x,y;
	bool operator < (node aa)const{
		return y==aa.y?x>aa.x:y>aa.y;
	}
}tmp,t[N<<2],ret;
priority_queue<node>pq[N<<2];
vector<int>son[N];
int dep[N],sz[N],n,cnt,fa[N],top[N],tg[N<<2],S[N],in[N];
void dfs(int now,int fat){
	dep[now]=dep[fat]+1;sz[now]=1;fa[now]=fat;
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fat){
			dfs(T,now);sz[now]+=sz[T];if(sz[T]>sz[S[now]])S[now]=T;
		}
	}
}
void dfs0(int now,int tp){
//	cout<<now<<" "<<tp<<"++\n";
	top[now]=tp;in[now]=++cnt;
	if(S[now])dfs0(S[now],tp);
	for(int T,i=0;i<son[now].size();++i){
		if((T=son[now][i])!=fa[now]&&T!=S[now])dfs0(T,T);
	}
}
void up(int k){
	if(t[ls]<t[rs])t[k]=t[rs];
	else t[k]=t[ls];
}
void down(int k){
	if(tg[k]){
		tg[ls]+=tg[k];
		tg[rs]+=tg[k];
		t[ls].y+=tg[k];
		t[rs].y+=tg[k];
		tg[k]=0;
	}
}
void build(int k,int l,int r){
	t[k].y=1e18;
	if(l^r)build(ls,l,mid),build(rs,mid+1,r); 
}
void add(int k,int l,int r,int x,int y){
	if(l==r){
		tmp.x=y;tmp.y=y;
		pq[k].push(tmp);
		t[k]=pq[k].top();t[k].y+=tg[k];
		return ;
	}
//	down(k);
	if(x<=mid)add(ls,l,mid,x,y);
	else add(rs,mid+1,r,x,y);
	up(k);
	if(t[k].x){
//		cout<<k<<" "<<l<<" "<<r<<" "<<t[k].x<<" "<<t[k].y<<"\n";
	}
}
node find(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[k];
	down(k);
	if(x>mid)return find(rs,mid+1,r,x,y);
	if(y<=mid)return find(ls,l,mid,x,y);
	return max(find(ls,l,mid,x,y),find(rs,mid+1,r,x,y));
}
void del(int k,int l,int r,int x){
	if(l==r){
		pq[k].pop();
		if(pq[k].size()){
			t[k]=pq[k].top();
			t[k].y+=tg[k];
		}
		else t[k].y=1e18,t[k].x=0;
		return ;
	}
	down(k);
	if(x<=mid)del(ls,l,mid,x);
	else del(rs,mid+1,r,x);
	up(k);
}
void add(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y){tg[k]+=v;t[k].y+=v;return ;}
	if(x>r||y<l)return ;down(k);
	down(k);add(ls,l,mid,x,y,v);add(rs,mid+1,r,x,y,v);up(k);
}
node find(int x,int y){
	int fl=0;
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		if(fl){
			ret=max(ret,find(1,1,n,in[top[y]],in[y]));
		}
		else ret=find(1,1,n,in[top[y]],in[y]),fl=1;
		y=fa[top[y]];
	}
	if(in[x]>in[y])swap(x,y);
	if(fl)ret=max(ret,find(1,1,n,in[x],in[y]));
	else ret=find(1,1,n,in[x],in[y]);
	return ret;
}
int m,q,i,x,y,c[N],hd,st[N],op,u,v,k;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(i=1;i<n;++i){
		cin>>x>>y,son[x].push_back(y),son[y].push_back(x);
//		if(i>=73)cout<<x<<" "<<y<<"\n";
	}
	dfs(1,0);dfs0(1,1);build(1,1,n);
	for(i=1;i<=m;++i){
		cin>>c[i];//cout<<in[c[i]]<<"\n";
		add(1,1,n,in[c[i]],i);
//		if(n>=20)cout<<c[i]<<" ";
	}//cout<<"\n";
	int ttt=0;
	while(q--){
		cin>>op;
		if(op==1){
			cin>>u>>v>>k;
			++ttt;
//			if(n>=20&&ttt==4)cout<<u<<" "<<v<<" "<<k<<"\n";
			hd=0;
			while(k){
				tmp=find(u,v);
				if(!tmp.x)break;
				else {
					st[++hd]=tmp.x;
					del(1,1,n,in[c[st[hd]]]);
				}
				--k;
			}
			cout<<hd<<" ";
			for(i=1;i<=hd;++i)cout<<st[i]<<" ";cout<<"\n";
		}
		else{
			cin>>u>>k;
			add(1,1,n,in[u],in[u]+sz[u]-1,k);
		}
	}
}