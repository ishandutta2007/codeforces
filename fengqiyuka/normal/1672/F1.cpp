#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
int a[N],Cnt[N],b[N],g[N];

struct node{
	int x,c;
	node(int _x,int _c) {x=_x;c=_c;}
	bool operator < (node a) const {
		if(c==a.c) return (x<a.x);
		return (c<a.c);
	}
};
set<node> S;
set<node>::iterator iter;

void del(int x){
	iter=S.find(node(x,Cnt[x]));
	S.erase(iter);Cnt[x]--;
	if(Cnt[x]) S.insert(node(x,Cnt[x]));
}

set<int> B[N];
set<int>::iterator iter2;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) Cnt[i]=0;
		for(int i=1;i<=n;i++) Cnt[a[i]]++;
		int Max=0,Max1=0;
		for(int i=1;i<=n;i++){
			if(Max<Cnt[i]) Max=Cnt[i],Max1=i;
		}
		for(int i=1;i<=n;i++)
			if(Cnt[i]) S.insert(node(i,Cnt[i]));
		for(int i=1;i<=n;i++){
			iter=S.end();iter--;
			if((*iter).x!=b[i-1]){
				b[i]=(*iter).x;
			}
			else{
				if(iter==S.begin()) b[i]=(*iter).x;
				else iter--,b[i]=(*iter).x;
			}
			del(b[i]);
		}
		
		for(int i=1;i<=n;i++) B[a[i]].insert(i);
		for(int i=1;i<=n;i++){
			iter2=B[b[i]].begin();
			g[i]=(*iter2);B[b[i]].erase(iter2);
		}
		
		for(int i=1;i<n;i++) b[g[i]]=g[i+1];
		b[g[n]]=g[1];
		for(int i=1;i<=n;i++) printf("%d ",a[b[i]]);
		printf("\n");
		
		S.clear();
		for(int i=1;i<=n;i++) B[i].clear();
	}
	
	return 0;
}