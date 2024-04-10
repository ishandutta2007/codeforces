#include<bits/stdc++.h>
using namespace std;

const int N=210,M=40100;
int b[N][N][N],dep[N];char s[N];
vector<int> B[N];
bool bk[N];

struct edge{
	int x,y,next;
}a[2*M];int len,last[N];
void ins(int x,int y){
	a[++len].x=x;a[len].y=y;
	a[len].next=last[x];last[x]=len;
}

int dis[N][N];
void dfs(int x){
	bk[x]=false;
	for(auto y:B[x]){
		if(bk[y]){
			dep[y]=dep[x]+1;
			dfs(y);
		}
	}
}

int fa[M],sta[M],Cnt[M];
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}


int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		len=1;memset(last,0,sizeof(last));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				scanf("%s",s+1);
				int Sum=0;
				for(int k=1;k<=n;k++){
					b[i][j][k]=b[j][i][k]=s[k]-'0';
					if(s[k]=='1') Sum++;
				}
				if(!Sum) ins(i,j),ins(j,i);
			}
		}
		
		for(int i=1;i<=len/2;i++) fa[i]=i;
		for(int i=1;i<=n;i++){
			int tot=0;
			for(int k=last[i];k;k=a[k].next) sta[++tot]=k;
			for(int j=1;j<=tot;j++)
				for(int k=j+1;k<=tot;k++){
					if(b[a[sta[j]].y][a[sta[k]].y][i]){
						int t1=Find(sta[j]/2),t2=Find(sta[k]/2);
						if(t1!=t2) fa[t1]=t2;
					}
				}
		}
		
		for(int i=1;i<=len/2;i++) Cnt[i]=0;
		for(int i=1;i<=len/2;i++) Cnt[Find(i)]++;
		
		bool pd=false;
		for(int p=1;p<=len/2;p++){
			if(Cnt[p]==n-1){
				for(int i=1;i<=n;i++) B[i].clear();
				pd=true;
				for(int j=1;j<=len/2;j++)
					if(Find(j)==p){
						B[a[j*2].x].push_back(a[j*2].y);
						B[a[j*2].y].push_back(a[j*2].x);
					}
					
				for(int i=1;i<=n;i++){
					dep[i]=0;
					for(int j=1;j<=n;j++) bk[j]=true;
					dfs(i);
					for(int j=1;j<=n;j++){
						if(bk[j]) {pd=false;break;}
						dis[i][j]=dep[j];
					}
					if(!pd) break;
				}
				if(!pd) continue;
				else{
					for(int i=1;i<=n;i++)
						for(int j=i+1;j<=n;j++)
							for(int k=1;k<=n;k++){
								if(b[i][j][k]==0&&dis[i][k]==dis[j][k]) pd=false;
								if(b[i][j][k]==1&&dis[i][k]!=dis[j][k]) pd=false;
							}
					if(!pd){
						continue;
					}
					else{
						printf("Yes\n");
						for(int i=1;i<=n;i++)
							for(auto y:B[i])
								if(i<y) printf("%d %d\n",i,y);
					}
				}
					
				if(pd) break;
			}
			if(pd) break;
		}
			
		if(!pd){
			printf("No\n");
		}
			
	}
	
	return 0;
}