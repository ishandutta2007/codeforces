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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main(){
	int n,m,h;
	scanf("%d %d %d",&n,&m,&h);
	int a[105],b[105];
	for(int i = 0;i<m;i++)
		scanf("%d",&a[i]);
	for(int j =0;j<n;j++)
		scanf("%d",&b[j]);
	int ans[105][105];
	for(int i =0;i<n;i++)
		for(int j = 0;j<m;j++){
			scanf("%d",&ans[i][j]);
			if(ans[i][j])
			ans[i][j]=min(b[i],a[j]);
		}
	for(int i = 0;i<n;i++){
		for(int j =0;j<m;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}