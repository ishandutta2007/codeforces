#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int to,next;
}e[200005];
int h[100005],fa[100005],p[100005][20],d[100005],n,m,cnt;
int addedge(int x,int y){
    e[++cnt].to=y;
    e[cnt].next=h[x];
    h[x]=cnt;
}
void dfs(int depth,int point,int father){
    d[point]=depth;
    fa[point]=father;
    for(int i=h[point];i;i=e[i].next)if(e[i].to!=father)dfs(depth+1,e[i].to,point);
}
void makeST(){
    for(int i=1;i<=n;i++)p[i][0]=fa[i];
    for(int i=1;i<=17;i++){
        for(int j=1;j<=n;j++){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
int lca(int a,int b){
    if(d[a]<d[b])swap(a,b);
    for(int i=17;i>=0;i--)if(d[a]-(1<<i)>=d[b])a=p[a][i];
    if(a==b)return b;
    for(int i=17;i>=0;i--)if(p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
    return p[a][0];
}
int dis(int x,int y){
	return d[x]+d[y]-2*d[lca(x,y)];
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    dfs(1,1,0);
    makeST();
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
    	int x,y,a,b,k;
    	scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
    	int d1=dis(a,b);
    	//cout<<d1<<' '<<d[a]<<' '<<d[b]<<' '<<d[lca(a,b)]<<' '<<lca(a,b)<<endl;
    	if(k>=d1&&(k-d1)%2==0){
    		puts("Yes");
    		continue;
		}
		int d2=dis(a,x)+dis(b,y)+1,d3=dis(a,y)+dis(b,x)+1;
		if(min(d1,min(d2,d3))>k){
			puts("No");
			continue;
		}
		if(k>=d2&&(k-d2)%2==0){
    		puts("Yes");
    		continue;
		}
		if(k>=d3&&(k-d3)%2==0){
    		puts("Yes");
    		continue;
		}
		puts("No");
	}
    return 0;
}