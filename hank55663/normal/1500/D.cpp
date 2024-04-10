#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define index Index
using namespace std;
pii v[1505][1505][11];
int index[1505][1505];
int vis[3000005];
int ans[3005];
int a[1505][1505];
bool solve(){
	int n,q;
	scanf("%d %d",&n,&q);

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
		//	a[i][j]=rand()%10000;
			scanf("%d",&a[i][j]);
		}
	}
	for(int i = 0;i<n;i++){
		//	printf("%d\n",i);
		for(int j = 0;j<n;j++){
			ans[min(i,j)+2]--;
		
			if(i==0||j==0){
				v[i][j][index[i][j]++]=mp(1,a[i][j]);
			}
			else{
				//vis[a[i][j]]=1;
			//	v[i][j].reserve(q+2);
				pii tmp[35];
				pii tmp2[25];
				//int idx=0;
				tmp[0]=mp(1,a[i][j]);
				merge(v[i-1][j],v[i-1][j]+index[i-1][j],v[i-1][j-1],v[i-1][j-1]+index[i-1][j-1],tmp2);
				merge(v[i][j-1],v[i][j-1]+index[i][j-1],tmp2,tmp2+index[i-1][j]+index[i-1][j-1],tmp+1);
				int idx=1+index[i-1][j]+index[i-1][j-1]+index[i][j-1];
				for(int x = 1;x<idx;x++){
					//tmp[idx]=v[i][j-1][x];
					tmp[x].x++;
				}
			//	sort(tmp,tmp+idx);
				for(int x=0;x<idx;x++){
				    if(tmp[x].x>min(i,j)+1)break;
					if(!vis[tmp[x].y]){
						vis[tmp[x].y]=1;
						v[i][j][index[i][j]++]=tmp[x];
					}
					if(index[i][j]==q+1)break;
				}
				if(index[i][j]==q+1){
					ans[v[i][j][q].x]--;
					ans[min(i,j)+2]++;
				}
				for(int x=0;x<index[i][j];x++)vis[v[i][j][x].y]=0;
			}
		}
	}
	int res=n*n;
	for(int i = 1;i<=n;i++){
		res+=ans[i];
		printf("%d\n",res);
	}
}
int main(){
	int t=1;//000000;
   
	while(t--)solve();
}