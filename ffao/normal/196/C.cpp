    #include<bits/stdc++.h>
    using namespace std;
    const int maxn=1520;
    int n,X,Y;
    struct PO{
    	int x,y,d;
    	bool operator<(const PO &o) const{
    		if(x-X>=0&&o.x-X<=0) return 1;
    		if(x-X<=0&&o.x-X>=0) return 0;
    		return (y-Y)*(long long)(o.x-X)<(o.y-Y)*(long long)(x-X);
    	}
    }p[maxn];
    vector<int> g[maxn];
    bool vis[maxn];
    int sz[maxn],o[maxn];
    int dfs(int u){
    	vis[u]=true;
    	sz[u]=1;
    	int ret=0;
    	for(int i=0,j=g[u].size();i<j;i++){
    		int v=g[u][i];
    		if(vis[v]) continue;
    		ret+=dfs(v);
    	}
    	sz[u]+=ret;
    	return sz[u];
    }
    void calc(int u,int l,int r){
    	vis[u]=true;
    	int t=l;
    	for(int i=l+1;i<=r;i++){
    		if((p[i].y<p[t].y)||(p[t].y==p[i].y&&p[i].x<p[t].x))
    			t=i;
    	}
    	if(t!=l) swap(p[l],p[t]);
    	o[p[l].d]=u;
    	X=p[l].x; Y=p[l].y;
    	sort(p+l+1,p+r+1);
    	int pos=l+1;
    	for(int i=0,j=g[u].size();i<j;i++){
    		int v=g[u][i];
    		if(vis[v]) continue;
    		calc(v,pos,pos+sz[v]-1);
    		pos+=sz[v];
    	}
    }
    int main(){
    	scanf("%d",&n);
    	for(int i=0;i<n-1;i++){
    		int x,y;
    		scanf("%d%d",&x,&y);
    		g[x].push_back(y); g[y].push_back(x);	
    	}
    	for(int i=1;i<=n;i++){
    		int x,y;
    		scanf("%d%d",&x,&y);
    		p[i]=(PO){x,y,i};	
    	}
    	dfs(1);
    	memset(vis,0,sizeof(vis));
    	calc(1,1,n);
    	for(int i=1;i<=n;i++)
    		printf("%d ",o[i]);
    	putchar(10);
    	return 0;
    }