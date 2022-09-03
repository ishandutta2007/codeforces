#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
using namespace std;
int a[1005][1005];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	map<int,int> r[1005];
	map<int,int> c[1005];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			r[i][a[i][j]];
			c[j][a[i][j]];
		}
	}
	for(int i=1;i<=n;i++){
		int index=1;
		for(auto &it:r[i])
			it.y=index++;
	}
	for(int i=1;i<=m;i++){
		int index=1;
		for(auto &it:c[i])
			it.y=index++;
	}
	for(int i=1;i<=n;i++,printf("\n")){
		for(int j=1;j<=m;j++){
			int Max=max(r[i][a[i][j]],c[j][a[i][j]]);
			int dis=max(r[i].rbegin()->y-r[i][a[i][j]],c[j].rbegin()->y-c[j][a[i][j]]);
			printf("%d ",Max+dis);//,Max,dis,r[i][a[i][j]],c[j][a[i][j]],r[i].rbegin()->y,c[j].rbegin()->y);
		}
	}
}