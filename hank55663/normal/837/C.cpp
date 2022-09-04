#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef long long LL;
int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	pii p[105];
	for(int i=0;i<n;i++){
		int c,d;
		scanf("%d %d",&c,&d);
		p[i]=mp(c,d);
	}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			for(int k=0;k<2;k++){
				if(p[i].x+p[j].x<=a&&max(p[i].y,p[j].y)<=b){
					ans=max(ans,p[i].x*p[i].y+p[j].x*p[j].y);
				} 
				if(p[i].x+p[j].y<=a&&max(p[i].y,p[j].x)<=b){
					ans=max(ans,p[i].x*p[i].y+p[j].x*p[j].y);
				}
				if(p[i].y+p[j].x<=a&&max(p[i].x,p[j].y)<=b){
					ans=max(ans,p[i].x*p[i].y+p[j].x*p[j].y);
				}
				if(p[i].y+p[j].y<=a&&max(p[i].x,p[j].x)<=b){
					ans=max(ans,p[i].x*p[i].y+p[j].x*p[j].y);
				}
				swap(a,b);
			}
		}
	printf("%d\n",ans);
}