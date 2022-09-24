#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,p[200005][20],pass[30],fine[30],fa[200005],T;
int c[15000005][2],rt[200005],tot;
int d[200005],tmpc[30],q;
char bel[200005],str[10];
ll dis[200005],s[200005][30];
struct E{
	int to,val;
};
struct Opt{
	int t,x;
};
vector<E> g[200005];
vector<Opt> v[200005];
void Ins(int &p,int l,int r,int x){
	p=++tot;
	if(l==r)return ;
	int mid=(l+r)/2;
	if(x<=mid)Ins(c[p][0],l,mid,x);
	else Ins(c[p][1],mid+1,r,x);
}
int Merge(int p,int q,int l,int r){
	if(!p||!q)return p+q;
	if(l>r)return 0;
	int rr=++tot,mid=(l+r)/2;
	c[rr][0]=Merge(c[p][0],c[q][0],l,mid);
	c[rr][1]=Merge(c[p][1],c[q][1],mid+1,r);
	return rr;
}
int Query(int p,int l,int r,int x,int y){
	if(!p)return 0;
	if(x<=l&&r<=y)return 1;
	int mid=(l+r)/2,re=0;
	if(x<=mid)re+=Query(c[p][0],l,mid,x,y);
	if(mid<y)re+=Query(c[p][1],mid+1,r,x,y);
	return re;
}
void dfs(int x,int f){
	p[x][0]=f,d[x]=d[f]+1,fa[x]=f;
	for(int i=1;i<=17;i++)p[x][i]=p[p[x][i-1]][i-1];
	Ins(rt[x],0,T-1,dis[x]%T);
	int lst=0;
	for(int i=m;i>=1;i--){
		int y=x;
		//>=i
		for(int j=17;j>=0;j--)if(bel[p[y][j]]>=i)y=p[y][j];
		//printf("SS %d %d\n",x,y);
		if(bel[y]!=i){
			s[x][i]=-1;
			continue;
		}
		if(bel[x]==i){
			lst=fa[y],s[x][i]=-1;
			continue;
		}
		s[x][i]=(dis[x]-dis[fa[y]]-1)/T-(dis[x]-dis[lst]-1)/T;
		ll I=dis[lst],O=dis[fa[y]]+1;
		I%=T,O%=T;
		if(O<=I){
			v[x].push_back({O,i});
			v[x].push_back({I+1,-i});
			s[x][i]=s[x][i]-(dis[x]%T>=O&&dis[x]%T<=I);
		}
		else {
			v[x].push_back({O,i});
			v[x].push_back({0,i});
			v[x].push_back({I+1,-i});
			s[x][i]=s[x][i]-(dis[x]%T<=I||dis[x]%T>=O);
		}
		lst=fa[y];
	}
	sort(v[x].begin(),v[x].end(),[](Opt x,Opt y){return x.t<y.t;});
	for(E i:g[x]){
		int y=i.to;
		if(y==f)continue;
		dis[y]=dis[x]+i.val,dfs(y,x);
		if(bel[x]==bel[y])rt[x]=Merge(rt[x],rt[y],0,T-1);
	}
	//printf("x=%d\n",x);
	//for(int i=1;i<=m;i++)printf("s[%d][%d]=%d\n",x,i,s[x][i]);
	//for(auto i:v[x]){
	//	printf("on vertex %d at %d, c[%d] is added %d\n",x,i.t,abs(i.x),i.x/abs(i.x));
	//}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	scanf("%d%s",&m,bel+1);
	for(int i=1;i<=n;i++)bel[i]-='A'-1;
	for(int i=1;i<=m;i++)scanf("%d",&pass[i]);
	for(int i=1;i<=m;i++)scanf("%d",&fine[i]);
	scanf("%d",&T);
	dfs(1,0);
	scanf("%d",&q);
	for(int i=1,op,x,y;i<=q;i++){
		scanf("%d",&op);
		if(op==1)scanf("%s%d",str,&y),pass[str[0]-'A'+1]=y;
		if(op==2)scanf("%s%d",str,&y),fine[str[0]-'A'+1]=y;
		if(op==3){
			scanf("%d",&x);
			if(bel[x]==1){
				puts("0");
				continue;
			}
			ll ans=1e18;
			if(v[x][0].t>0){
				if(Query(rt[x],0,T-1,0,v[x][0].t-1)){
					ll sum=0;
					for(int o=1;o<=m;o++)
						if(s[x][o]!=-1){
							if(s[x][o]>2e9)sum+=pass[o];
							else sum+=min(s[x][o]*fine[o],(ll)pass[o]);
						}
					ans=min(ans,sum);
				}
			}
			memset(tmpc,0,sizeof(tmpc));
			for(int j=0,k;j<v[x].size();j=k+1){
				if(v[x][j].t>=T)break;
				k=j;
				if(v[x][k].x>0)tmpc[v[x][k].x]++;
				else tmpc[-v[x][k].x]--;
				while(k+1<v[x].size()&&v[x][k+1].t==v[x][j].t){
					k++;
					if(v[x][k].x>0)tmpc[v[x][k].x]++;
					else tmpc[-v[x][k].x]--;
				}
				int L=v[x][j].t,R;
				if(k+1==v[x].size())R=T-1;
				else R=v[x][k+1].t-1;
				if(Query(rt[x],0,T-1,L,R)){
					//printf("Trying:%d %d\n",L,R);
					ll sum=0;
					for(int o=1;o<=m;o++)
						if(s[x][o]!=-1){
							if(s[x][o]>2e9)sum+=pass[o];
							else sum+=min((s[x][o]+tmpc[o])*fine[o],(ll)pass[o]);
						}
					ans=min(ans,sum);
				}
			}
			cout<<ans<<'\n';
		}
	}
}