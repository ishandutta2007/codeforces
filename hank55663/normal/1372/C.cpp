#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int z=1;
		vector<int> v;
		for(int i = 1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x==i)v.pb(i);
			else z=0;
		}
		if(z)printf("0\n");
		else{
			int vis[200005];
			fill(vis,vis+n+1,0);
			for(auto it:v)vis[it]=1;
			int cnt=0;
			for(int i = 1;i<n;i++){
				if(vis[i]!=vis[i+1])cnt++;
			}
			if(cnt<=1)printf("1\n");
			else if(cnt==2&&vis[1]==1)printf("1\n");
			else printf("2\n");
		}
	}
	return 0;
}