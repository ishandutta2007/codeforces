#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
int a[N],nex[N],b[N],g[N],Cnt[N],L[N],R[N];
map<int,int> B;
vector<int> G[N];

int mymin(int x,int y) {return (x<y?x:y);}
int mymax(int x,int y) {return (x>y?x:y);}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			nex[i]=B[a[i]];
			B[a[i]]=i;
		}
		for(int i=1;i<=n;i++) b[i]=n+1;
		for(int i=1;i<=m;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			b[r]=mymin(b[r],l);
		}
		
		int Min=n+1;bool pd=false;
		for(int i=0;i<=n+1;i++) L[i]=1e9,R[i]=-1e9,Cnt[i]=0;
		for(int i=n;i>=1;i--){
			Min=mymin(Min,b[i]);
			g[i]=Min;
			if(nex[i]>=Min){
				pd=true;
				L[B[a[i]]]=mymin(L[B[a[i]]],i);
				R[B[a[i]]]=mymax(R[B[a[i]]],i);
			}
		}
		
		int AnsL=1e9,AnsR=-1e9;
		for(int i=1;i<=n;i++)
			if(L[i]<=R[i]){
				int t1=nex[L[i]],t2=R[i];
				if(t1>=g[t2]){
					Cnt[t2]++;Cnt[nex[t2]]++;
					G[t1].push_back(t2);
					AnsL=mymin(AnsL,L[i]);
				}
				else{
					Cnt[nex[t2]]++;
					AnsL=mymin(AnsL,L[i]);
				}
			}
			
		int id=n,Ans=1e9;
		
		if(AnsL==1e9) Ans=0;
		else{
			for(int i=n;i>=1;i--){
				for(auto y:G[i])
					Cnt[y]--;
				while(Cnt[id]==0) id--;
				if(i<=AnsL) Ans=mymin(Ans,id-i+1);
			}
		}
		
		printf("%d\n",Ans);
		
		B.clear();
		for(int i=1;i<=n;i++) G[i].clear();
	}
	
	return 0;
}