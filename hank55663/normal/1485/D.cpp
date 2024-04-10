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
using namespace std;
bool solve(){
	int vis[17];
	fill(vis,vis+17,-1);
	for(LL i = 1;i*i*i*i<=720720;i++){
		int x=720720-i*i*i*i;
		for(int j = 1;j<=16;j++){
			if(x%j==0)vis[j]=x;
		}
	}
	int n,m;
	scanf("%d %d",&n,&m);
	int a[505][505];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++)scanf("%d",&a[i][j]);
	}
	for(int i=0;i<n;i++){
		for(int j =0;j<m;j++){
			if((i+j)%2==0)printf("720720 ");
			else printf("%d ",vis[a[i][j]]);
		}
		printf("\n");
	}
}
int main(){
	int t=1;//000000;
   // scanf("%d",&t);
    while(t--)solve();
}