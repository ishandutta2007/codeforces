#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
using namespace std;
vector<pii> v;
int node;
int d[305];
void dfs(int l,int r,int k){
	if(l>r)node=1;
	else if(l==r){
		node=d[l]-k+1;
		for(int i = 1;i<=node;i++)
			for(int j = i + 1;j<=node;j++)
				v.pb(mp(i,j));
	}
	else{
		dfs(l+1,r-1,d[l]);
		node+=d[r]-d[r-1];
		for(int i = node+1;i<=node+d[l]-k;i++){
			for(int j =1;j<i;j++)
				v.pb(mp(i,j));
		}
		node+=d[l]-k;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
		scanf("%d",&d[i]);
	dfs(0,n-1,0);
	printf("%d\n",v.size());
	for(auto it:v)
	printf("%d %d\n",it.x,it.y);
}