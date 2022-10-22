#include<bits/stdc++.h>
using namespace std;

const int N=210;
int a[N],ID[N],g[N],fa[N],Ans[N],Lc[N],Rc[N],bz[N],tmp[N],p1[N],p2[N];bool bk[N],vis[N],Loop[N];

int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}

int mymax(int x,int y) {return (x>y?x:y);}
int mymin(int x,int y) {return (x<y?x:y);}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),ID[a[i]]=i;
		
		memset(bk,true,sizeof(bk));
		int tot=0;
		for(int i=1;i<=n;i++)
			if(bk[i]){
				int t=i;tot++;
				while(bk[t]) bk[t]=false,g[t]=tot,t=a[t];
			}
		
		memset(bz,0,sizeof(bz));
		memset(vis,true,sizeof(vis));vis[1]=false;
		memset(Loop,false,sizeof(Loop));
		memset(Lc,0,sizeof(Lc));
		memset(Rc,0,sizeof(Rc));
		memset(p1,0,sizeof(p1));
		memset(p2,0,sizeof(p2));
		Ans[1]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++)
				if(vis[j]){
					int t=a[j];bool tran=false;
					int L=t,R=Ans[i-1];
					if(L>R) swap(L,R),tran=true;
					
					for(int k=1;k<=n;k++) tmp[k]=bz[k];
					
					vis[j]=false;
					bool pd=true;
					if(L==R){
						if(bz[L]) pd=false;
					}
					else{
						for(int k=1;k<n;k++){
							if(tran&&p1[k]){
								int t1=mymax(L,k),t2=mymin(R,p1[k]);
								if(t2-t1>=2) {pd=false;break;}
							}
							if(!tran&&p2[k]){
								int t1=mymax(L,k),t2=mymin(R,p2[k]);
								if(t2-t1>=2) {pd=false;break;}
							}
						}
						
						for(int k=L;k<R;k++){
							if(tran&&(bz[k]&1)) {pd=false;break;}
							if(!tran&&(bz[k]&2)) {pd=false;break;}
							if(Loop[k]) {pd=false;break;}
						}
							
						for(int k=L;k<R;k++){
							if(!tran) bz[k]|=2;
							else bz[k]|=1;
						}
					}
						
					for(int k=1;k<=tot;k++) fa[k]=k;
					for(int k=1;k<n;k++)
						if(bz[k]){
							int t1=Find(g[k]),t2=Find(g[k+1]);
							if(t1==t2) {pd=false;break;}
							fa[t1]=t2;
						}
					
					if(L==R) Loop[L]=true;
					else Lc[L]++,Rc[R]++;	
					for(int k=1;k<=tot;k++) fa[k]=k;
					for(int k=1;k<n;k++)
						if(!Loop[k]&&!Loop[k+1]&&Rc[k]<2&&Lc[k+1]<2){
							int t1=Find(g[k]),t2=Find(g[k+1]);
							fa[t1]=t2;
						}
					for(int k=1;k<tot;k++)
						if(Find(k)!=Find(k+1)) {pd=false;break;}
					
					if(!pd){
						if(L==R) Loop[L]=false;
						else Lc[L]--,Rc[R]--;
						vis[j]=true;
						for(int k=1;k<=n;k++) bz[k]=tmp[k];
						continue;
					}
					
					if(L<R){
						if(!tran) p1[L]=R;
						else p2[L]=R;
					}
					a[j]=Ans[i-1];Ans[i]=j;
					
					break;
				}
		}
		
		for(int i=1;i<=n;i++) ID[a[i]]=i;
		int t=1;
		for(int i=1;i<=n;i++) printf("%d ",t),t=ID[t];
		printf("\n");
	}
	
	return 0;
}