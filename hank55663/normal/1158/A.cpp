#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int b[100005];
	int g[100005];
	for(int i = 0;i<n;i++){
		scanf("%d",&b[i]);
	}
	sort(b,b+n);
	for(int i =0;i<m;i++){
		scanf("%d",&g[i]);
	}
	sort(g,g+m);
	if(g[0]<b[n-1]){
		printf("-1\n");
		return 0;
	}
	LL ans=0;
	for(int i = 0;i<n;i++){
		ans+=(LL)b[i]*m;
	}
	for(int i = 0;i<m;i++){
		ans+=g[i]-b[n-1];
	}
	if(g[0]!=b[n-1]){
		ans+=b[n-1]-b[n-2];
	}
	printf("%lld\n",ans);
	return 0;
}
/*
n = x*m+x=x*(m+1);



*/