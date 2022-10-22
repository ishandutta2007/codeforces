#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define mymax(x,y) ((x)>(y)?(x):(y))
#define e 0.0000000001
using namespace std;
typedef long double db;
const int N=1e5+100,maxn=17;
struct edge{
	int x,y,next;
}a[2*N];int len,last[N];db ti;
struct ques{
	int t,c,u,v; 
}b[N];
struct str{
	int st,ty,id,c,ed,p;db x;
}tr[40*N];int Sum=0;
void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}
bool bk[N];int size[N],fa[N][20],son[N],top[N],dfn[N],sum=0,deep[N];
void dfs(int x){
	for(int i=1;i<=maxn;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	bk[x]=false;
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(bk[y]){
			fa[y][0]=x;deep[y]=deep[x]+1;
			dfs(y);
			size[x]+=size[y];
			if((!son[x])||size[y]>size[son[x]]) son[x]=y;
		}
	}
	size[x]++;
}
void dfs2(int x){
	dfn[x]=++sum;
	if(son[x]) top[son[x]]=top[x],dfs2(son[x]);
	for(int k=last[x];k;k=a[k].next){
		int y=a[k].y;
		if(fa[y][0]==x&&y!=son[x]) top[y]=y,dfs2(y);
	}
}
int findlca(int x,int y){
	for(int i=maxn;i>=0;i--){
		if(deep[fa[x][i]]>=deep[y]) x=fa[x][i];
		if(deep[fa[y][i]]>=deep[x]) y=fa[y][i];
	}
	for(int i=maxn;i>=0;i--){
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	}
	if(x!=y) x=fa[x][0],y=fa[y][0];
	return x;
}
int comp(db n1,db n2){
	if(n1-n2<=e&&n2-n1<=e) return 0;
	if(n1<n2) return -1;
	return 1;
}
bool cmp(str n1,str n2){
	if(comp(n1.x,n2.x)==0&&n1.p==n2.p) return (n1.ty<n2.ty);
	else if(comp(n1.x,n2.x)==0) return (n1.p<n2.p);
	return (n1.x<n2.x);
}
struct fkcmp{
	bool operator ()(int u,int v){
		if(comp((ti-tr[u].x)*tr[u].c+tr[u].st,(ti-tr[v].x)*tr[v].c+tr[v].st)==0)
			return (u<v);
		return (comp((ti-tr[u].x)*tr[u].c+tr[u].st,(ti-tr[v].x)*tr[v].c+tr[v].st)==-1);
	}
};
set<int,fkcmp> s;
set<int,fkcmp>::iterator it,itl,itr;
db Min=1e99;
void update(int n1,int n2){
	db st1=tr[n1].st-tr[n1].x*tr[n1].c;
	db st2=tr[n2].st-tr[n2].x*tr[n2].c;
	db t2,t;
	if(tr[n2].c==tr[n1].c){
		if(comp(st1,st2)!=0) return ;
		if(Min>tr[n1].x){
			if(comp(tr[n1].x,tr[n2].x)==1) t=tr[n1].st,t2=tr[n1].x;
			else t=tr[n2].st,t2=tr[n2].x;
		}
	}
	else{
		t2=(st1-st2)/(tr[n2].c-tr[n1].c);
		t=t2*tr[n1].c+st1;
	}
	if(comp(tr[n1].st,t)==1&&comp(tr[n1].ed,t)==1) return ;
	if(comp(tr[n1].st,t)==-1&&comp(tr[n1].ed,t)==-1) return ;
	if(comp(tr[n2].st,t)==1&&comp(tr[n2].ed,t)==1) return ;
	if(comp(tr[n2].st,t)==-1&&comp(tr[n2].ed,t)==-1) return ;
	if(tr[n1].p==2&&comp(tr[n1].st,t)==0) return ;
	if(tr[n1].p==0&&comp(tr[n1].ed,t)==0) return ;
	if(tr[n2].p==2&&comp(tr[n2].st,t)==0) return ;
	if(tr[n2].p==0&&comp(tr[n2].ed,t)==0) return ;
	if(Min>t2) Min=t2;
}
int P[40*N];
void solve(){
	for(int i=1;i<=Sum;i++){
		if(i==5){
			i++;i--;
		}
		if(comp(tr[i].x,Min)>=0) break;
		//for(it=s.begin(); it!=s.end(); it++) printf("%d ",*it);printf(":%d %.5Lf\n",i,ti);
		if(tr[i].ty==0){
			ti=tr[i].x;
			it=s.insert(i).first;
			P[tr[i].id]=i;
			itl=it,itr=it,itr++;
			if(it!=s.begin())
				update(i,*(--itl));
			if(itr!=s.end())
				update(i,*itr);
		}
		else if(tr[i].ty==1){
			it=s.find(P[tr[i].id]);
			//printf("P:%d\n",P[tr[i].id]);
			itl=it,itr=it,itr++;
			//if(it==s.end()) puts("error");
			//printf("%d %d %d %d %d\n",(it!=s.begin()),(it==s.begin()?-1:*(--itl)),(itr!=s.end()),(itr==s.end()?-1:*itr),
			//*it);
			if(it!=s.begin()) itl++;
			if(it!=s.begin()&&itr!=s.end()){
				itl--;
				update(*itl,*itr);
			}
			//for(it=s.begin(); it!=s.end(); it++) printf("%d ",*it);printf(":%d\n",i);
			s.erase(P[tr[i].id]);
			//for(it=s.begin(); it!=s.end(); it++) printf("%d ",*it);printf(":%d\n",i);
		}
	}
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	len=0;memset(last,0,sizeof(last));
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);
	}
	memset(bk,true,sizeof(bk));
	deep[1]=1;dfs(1);
	top[1]=1;dfs2(1);
	int sum2=0;
	for(int i=1;i<=m;i++){
		if(i==2){
			i++;i--;
		}
		scanf("%d%d%d%d",&b[i].t,&b[i].c,&b[i].u,&b[i].v);
		int lca=findlca(b[i].u,b[i].v);
		bool pd=true;int t=b[i].u;db t2=b[i].t;
		while(1){
			if(b[i].u==lca) break;
			if(deep[top[t]]>deep[lca]){
				tr[++Sum].x=t2;tr[Sum].st=dfn[t];tr[Sum].ed=dfn[top[t]]-1;
				tr[Sum].p=0;tr[Sum].c=-b[i].c;tr[Sum].ty=0;tr[Sum].id=++sum2;
				t2=t2+(deep[t]-deep[fa[top[t]][0]])*1.0/b[i].c;
				tr[++Sum].x=t2;tr[Sum].c=b[i].c;tr[Sum].ty=1;tr[Sum].id=sum2;tr[Sum].p=0;
			}
			else{
				tr[++Sum].x=t2;tr[Sum].st=dfn[t];tr[Sum].ed=dfn[lca];
				tr[Sum].p=0;tr[Sum].c=-b[i].c;tr[Sum].ty=0;tr[Sum].id=++sum2;
				t2=t2+(deep[t]-deep[lca])*1.0/b[i].c;
				tr[++Sum].x=t2;tr[Sum].c=b[i].c;tr[Sum].ty=1;tr[Sum].id=sum2;tr[Sum].p=0;
				break;
			}
			if(deep[top[t]]<=deep[lca]+1) break;
			t=fa[top[t]][0];
		}
		t2=b[i].t+(deep[b[i].u]+deep[b[i].v]-2*deep[lca])*1.0/b[i].c;t=b[i].v;
		while(1){
			if(b[i].v==lca) break;
			if(deep[top[t]]>deep[lca]){
				tr[++Sum].x=t2;tr[Sum].c=b[i].c;tr[Sum].ty=1;tr[Sum].id=++sum2;tr[Sum].p=2;
				t2=t2-(deep[t]-deep[fa[top[t]][0]])*1.0/b[i].c;
				tr[++Sum].x=t2;tr[Sum].st=dfn[top[t]]-1;tr[Sum].ed=dfn[t];
				tr[Sum].p=2;tr[Sum].c=b[i].c;tr[Sum].ty=0;tr[Sum].id=sum2;
			}
			else{
				tr[++Sum].x=t2;tr[Sum].c=b[i].c;tr[Sum].ty=1;tr[Sum].id=++sum2;tr[Sum].p=2;
				t2=t2-(deep[t]-deep[lca])*1.0/b[i].c;
				tr[++Sum].x=t2;tr[Sum].st=dfn[lca];tr[Sum].ed=dfn[t];
				tr[Sum].p=2;tr[Sum].c=b[i].c;tr[Sum].ty=0;tr[Sum].id=sum2;
				break;
			}
			if(deep[top[t]]<=deep[lca]+1) break;
			t=fa[top[t]][0];
		}
		tr[++Sum].x=t2;tr[Sum].st=tr[Sum].ed=dfn[lca];
		tr[Sum].c=b[i].c;tr[Sum].ty=0;tr[Sum].id=++sum2;tr[Sum].p=1;
		tr[++Sum].x=t2;tr[Sum].ty=1;tr[Sum].id=sum2;tr[Sum].p=1;
	}
	sort(tr+1,tr+Sum+1,cmp);
	solve();
	double MIN=Min;
	if(MIN<1e9) printf("%.7lf\n",MIN);
	else printf("-1\n");
	return 0;
}