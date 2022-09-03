#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int fi[100005];
int vis[100005];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i = 1 ;i<=k;i++){
		int x;
		scanf("%d",&x);
		if(vis[x]==0)
		fi[x]=i;
		vis[x]=i;
	}
	int ans=0;
	for(int i = 1;i<=n;i++){
		if(vis[i]==0){
			if(i!=1)
			ans++;
			if(i!=n)
			ans++;
			ans++;
		}
		else{
			if(i!=n&&vis[i+1]<fi[i])ans++;
			if(i!=1&&vis[i-1]<fi[i])ans++;
		}
	}
	printf("%d\n",ans);
}
/*

2*5!     240
2*4!*5   240
2*3!*10 120
2*2!*10 40
2*1!*5  10
2    2

*/