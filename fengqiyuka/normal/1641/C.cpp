#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

const int N=2e5+100;
set<int> S[N];
set<int>::iterator iter;
int fa[N],L[N],R[N];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	
	int n,q;scanf("%d%d",&n,&q);
	
	for(int i=0;i<=n;i++) fa[i]=L[i]=R[i]=i;
	for(int i=1;i<=q;i++){
		int op;scanf("%d",&op);
		if(op==0){
			int l,r,X;
			scanf("%d%d%d",&l,&r,&X);
			
			if(X==0){
				int t1=find(l-1);
				while(R[t1]<r){
					int t2=find(R[t1]+1);
					if(S[t1].size()<S[t2].size()){
						while(!S[t1].empty()){
							iter=S[t1].begin();
							S[t2].insert(*iter);S[t1].erase(iter);
						}
						fa[t1]=t2;L[t2]=L[t1];
					}
					else{
						while(!S[t2].empty()){
							iter=S[t2].begin();
							S[t1].insert(*iter);S[t2].erase(iter);
						}
						fa[t2]=t1;R[t1]=R[t2];
					}
					t1=find(t1);
				}
			}
			else{
				int t1=find(l-1),t2=find(r);
				S[t1].insert(t2);S[t2].insert(t1);
			}
		}
		else{
			int x;scanf("%d",&x);
			int t1=find(x-1),t2=find(x);
			if(t1==t2) printf("NO\n");
			else{
				iter=S[t2].lower_bound(L[t1]);
				if(iter!=S[t2].end()&&(*iter)<=R[t1]) printf("YES\n");
				else printf("N/A\n");
			}
		}
	}
	
	return 0;
}