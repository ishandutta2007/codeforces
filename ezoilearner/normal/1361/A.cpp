#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
#define Maxn 500010
int p[Maxn];

vector<int> vec[Maxn];
bool cmp(int z1,int z2){return p[z1]<p[z2];}

int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
int Q[Maxn],hd,tl,in[Maxn];
bool vis[Maxn];
void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;in[e]++;}

int main(){
	scanf("%d%d",&n,&m);
	int s,e;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&s,&e);
		vec[s].push_back(e);
		vec[e].push_back(s);
	}
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i){
		sort(vec[i].begin(),vec[i].end(),cmp);
		int len=vec[i].size(),at=0;
		while(at<len&&p[vec[i][at]]<p[i]){
			vis[p[vec[i][at]]]=true;
			add_edge(vec[i][at],i);
			at++;
		}
		for(int j=1;j<p[i];++j)
		    if(!vis[j]){
				puts("-1");
				return 0;
		    }
		for(int j=1;j<p[i];++j)vis[j]=false;
		while(at<len&&p[vec[i][at]]<=p[i]){
		    puts("-1");
		    return 0;
		}
	}
	for(int i=1;i<=n;++i)
	    if(!in[i]){
			Q[tl++]=i;
	    }
	while(hd<tl){
		int u=Q[hd];hd++;
		for(int i=head[u];i;i=nxt[i]){
			in[v[i]]--;
			if(!in[v[i]])Q[tl++]=v[i];
		}
	}
	for(int i=1;i<=n;++i)
	    if(in[i]){
			puts("-1");
			return 0;
	    }
	for(int i=0;i<n;++i)printf("%d ",Q[i]);
	puts("");
	return 0;
}