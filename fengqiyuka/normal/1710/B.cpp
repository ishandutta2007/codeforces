#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
struct node{
	int x,c;
}a[N];int sta[3*N],tot,qz[3*N];

bool cmp(int n1,int n2) {return (n1<n2);}

map<int,int> B;ll f[N*3],g[N*3],b[N*3];

ll mymax(ll x,ll y) {return (x>y?x:y);}

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		
		tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].c);
			sta[++tot]=a[i].x;
			sta[++tot]=a[i].x-a[i].c;
			sta[++tot]=a[i].x+a[i].c;
		}
		sort(sta+1,sta+tot+1,cmp);
		
		int cnt=0;
		for(int i=1;i<=tot;i++){
			if(B[sta[i]]==0) B[sta[i]]=++cnt,sta[cnt]=sta[i];
		}
		
		for(int i=0;i<=cnt;i++) qz[i]=0;
		for(int i=1;i<=n;i++){
			qz[B[a[i].x-a[i].c]]++;
			qz[B[a[i].x+a[i].c]]++;
			qz[B[a[i].x]]-=2;
		}
		
		for(int i=1;i<=cnt;i++) qz[i]+=qz[i-1];
		
		f[1]=-1e18;
		for(int i=2;i<=cnt;i++){
			b[i]=b[i-1]+(ll)qz[i-1]*(sta[i]-sta[i-1]);
			if(b[i]>m) f[i]=b[i]-m-sta[i];else f[i]=-1e18;
			f[i]=mymax(f[i],f[i-1]);
		}
		g[cnt]=-1e18;
		for(int i=cnt-1;i>=1;i--){
			if(b[i]>m) g[i]=b[i]-m+sta[i];else g[i]=-1e18;
			g[i]=mymax(g[i],g[i+1]);
		}
		
		for(int i=1;i<=n;i++){
			int x=B[a[i].x];
			if(f[x]<=a[i].c-a[i].x&&g[x]<=a[i].c+a[i].x) printf("1");
			else printf("0");
		}
		
		printf("\n");
		
		
		B.clear();
	}
	
	return 0;
}