#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
std::priority_queue<int>q;
int n,k,p[maxn],c[maxn],rank[maxn];
ll ans[maxn]={0};

int cmp(int a,int b){return p[a]<p[b];}

void ins(int p1){q.push(c[p1]);}
ll query(int k,int s){
	std::stack<int>stk;
	ll res=0;
	int k1=k;
	for(int i=1;i<=k1;++i){
		if (q.empty()){
			while (!stk.empty()){q.push(stk.top());stk.pop();}break;
		}
		int x=q.top();q.pop();
		res+=x;stk.push(x);
	//	printf("+= %d ",x);
		if (x==c[s])k1=k+1;
	}if (k1==k)res+=c[s];

	while (!stk.empty()){q.push(stk.top());stk.pop();}return res;
	
}
		
		

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)rank[i]=i;std::sort(rank+1,rank+n+1,cmp);
	int p1=0;
	for(int i=1;i<=n;++i){
		while (p1<n&&p[rank[p1+1]]==p[rank[i]]){ins(rank[1+p1]);++p1;}
		ans[rank[i]]=query(k,rank[i]);
	}for(int i=1;i<=n;++i)std::cout<<ans[i]<<" ";
	return 0;
}