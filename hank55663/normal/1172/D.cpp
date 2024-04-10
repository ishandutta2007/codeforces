#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int ans[1005][1005];
int main(){
	int n;
	scanf("%d",&n);
	int r[1005],c[1005];
	for(int i = 1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i =1;i<=n;i++)
		scanf("%d",&c[i]);
	int cnt= 1;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(c[j]==i){
				swap(c[j],c[i]);
				if(j==i)
					break;
				else
					ans[i][i]=ans[i][j]=cnt++;
			}
		}
	}
	for(int i = 1;i<n;i++){
		for(int j = i;j<=n;j++){
			if(r[j]==i){
				swap(r[j],r[i]);
				if(j==i)
					break;
				else{
					if(ans[i][i]==0&&ans[j][i]==0){
						ans[i][i]=ans[j][i]=cnt++;
					}
					else{
						swap(ans[i][i],ans[j][i]);
					}
				}
			}
		}
	}
	vector<vector<pii> > res(cnt);
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++){
			if(ans[i][j])
				res[ans[i][j]].pb(mp(i,j));
		}
	printf("%d\n",cnt-1);
	for(int i = 1;i<cnt;i++)
		printf("%d %d %d %d\n",res[i][0].x,res[i][0].y,res[i][1].x,res[i][1].y);
}