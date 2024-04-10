#include <bits/stdc++.h>
#define maxn 1024
int n,k,c[maxn],belong[maxn],M;
int cnt = 0;
char s[1000];

int query(int l,int r){
	cnt ++;
	printf("? %d ",r-l+1);int rt;
	for(int i=l;i<=r;++i)printf("%d ",i);printf("\n");
	fflush(stdout);
	scanf("%d",&rt);
	assert(rt != -1);
	//printf(">>%d<<\n",rt);
	return rt;
}

int solve(int l,int r){
	if (l == r) return l;
	int mid = (l+r)>>1;
	if (query(l,mid) == M) return solve(l,mid);
	else return solve(mid+1,r);
}

void solve(){
	cnt = 0;
	scanf("%d%d",&n,&k);
	std::memset(belong,0,sizeof(belong));
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=c[i];++j){
			int x;
			scanf("%d",&x);
			belong[x] = i;
		}
	}
	M = query(1,n);
	int max = solve(1,n);
	int S = belong[max];
	if (!S) {
		printf("! "); for(int i=1;i<=k;++i)printf("%d ",M);puts("");
		fflush(stdout);
		scanf("%s",s+1);
		return;
	}
	int d;
	printf("? "); 
	int sum = 0;
	for(int i=1;i<=n;++i)if(belong[i]!=S)sum++;
	printf("%d ",sum);
	for(int i=1;i<=n;++i)if(belong[i]!=S)printf("%d ",i); puts("");
	fflush(stdout);
	assert(cnt <= 11);
	scanf("%d",&d);
	printf("! ");
	for(int i=1;i<=k;++i) printf("%d ",i == S ? d : M);
	fflush(stdout);
	scanf("%s",s+1);
	assert(s[1] == 'C'); 
}

int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}