#include<bits/stdc++.h>
using namespace std;

const int N=3e5+100,maxn=19;
int p[N],a[N],sta[N],sta2[N],b[N],w1[N],w2[N],Log[N],Max[N][21],L[N],R[N],ID[N];

bool cmp(int n1,int n2) {return (n1<n2);}

set<int> S;
set<int>::iterator iter;

struct node{
	int l,r;
	node() {}
	node(int _l,int _r) {l=_l;r=_r;}
}g[N];

bool cmp1(node n1,node n2) {return (n1.r<n2.r);}
bool cmp2(node n1,node n2) {return (n1.l>n2.l);} 

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n,q;
		scanf("%d%d",&n,&q);
		
		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
		
		int tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(!a[i]) sta[++tot]=i;
		}
		
		for(int i=1;i<tot;i++) scanf("%d",&b[i]);
		
		int tot2=1;
		sta2[1]=0;p[0]=p[n+1]=1e9;
		for(int i=1;i<=n;i++){
			while(tot2&&p[sta2[tot2]]<p[i]) tot2--;
			L[i]=sta2[tot2];
			sta2[++tot2]=i;
		}
		tot2=1;sta2[1]=n+1;
		for(int i=n;i>=1;i--){
			while(tot2&&p[sta2[tot2]]<p[i]) tot2--;
			R[i]=sta2[tot2];
			sta2[++tot2]=i;
		}
		
		for(int i=1;i<=n;i++) ID[p[i]]=i;
		
		for(int i=1;i<=n;i++) Max[i][0]=a[i];
		for(int i=1;i<=maxn;i++){
			int t=(1<<(i-1));
			for(int j=1;j<=n;j++){
				if(j+t>n) Max[j][i]=Max[j][i-1];
				else Max[j][i]=std::max(Max[j][i-1],Max[j+t][i-1]);
			}
		}
		Log[1]=0;for(int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
		
		bool pd=true;
		for(int i=1;i<=n;i++){
			int x=L[i]+1,y=R[i]-1;
			int Len=Log[y-x+1];
			w1[i]=std::max(Max[x][Len],Max[y-(1<<Len)+1][Len]);
			if(a[i]&&w1[i]>a[i]) pd=false;
		}
		
		for(int i=0;i<=n+1;i++) w2[i]=1e9;
		for(int i=n;i>=1;i--){
			int x=ID[i];
			w2[x]=std::min(w2[L[x]],w2[R[x]]);
			if(w2[x]<a[x]) pd=false;
			if(a[x]) w2[x]=std::min(w2[x],a[x]);
		}
		
		for(int i=1;i<tot;i++) S.insert(b[i]);
		
		for(int i=1;i<=tot;i++) g[i]=node(w1[sta[i]],w2[sta[i]]);
		sort(g+1,g+tot+1,cmp1);
		
		int t1=-1,t2=-1;
		for(int i=1;i<=tot;i++){
			iter=S.lower_bound(g[i].l);
			if(iter==S.end()||(*iter)>g[i].r){
				if(t2==-1) t2=g[i].r;
				else {pd=false;break;}
			}
			else S.erase(iter);
		}
		
		S.clear();
		for(int i=1;i<tot;i++) S.insert(b[i]);
		
		sort(g+1,g+tot+1,cmp2);
		for(int i=1;i<=tot;i++){
			iter=S.lower_bound(g[i].r+1);
			int t;
			if(iter==S.begin()) t=-1e9;
			else iter--,t=(*iter);
			if(t<g[i].l){
				if(t1==-1) t1=g[i].l;
				else {pd=false;break;}
			}
			else S.erase(iter);
		}
		
		for(int i=1;i<=q;i++){
			int c;scanf("%d",&c);
			if(!pd) printf("NO\n");
			else{
				if(c>=t1&&c<=t2) printf("YES\n");
				else printf("NO\n");
			}
		}
	
		S.clear();
	}
	
	return 0;
}