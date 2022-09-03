
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
pll operator-(const pll &a,const pll &b){
	return {a.x-b.x,a.y-b.y};
}
LL cross(const pll &a,const pll &b){
	return a.x*b.y-a.y*b.x;
}
LL cross(const pll &a,const pii &b,const pll &c){
	return cross(a-c,b-c);
}
bitset<305> ok[305][305];
int main(){
	int n;
	scanf("%d",&n);
	pll p[305];
	for(int i = 0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i]=mp(x,y);
	}
	sort(p,p+n);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i!=j){
				for(int k =0;k<n;k++){
					if(k!=i&&k!=j){
						if(cross(p[j],p[k],p[i])>0){
							ok[i][j][k]=1;
						}
					}
				}
			}
		}
	}
	LL ans=0;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			for(int k=i+1;k<n;k++){
				if(j!=k&&cross(p[j],p[k],p[i])>0){
					int a=(ok[i][j]&ok[i][k]&ok[j][k]).count();
					int b=(ok[i][j]&ok[k][j]&ok[k][i]).count();
					int c=(ok[j][i]&ok[j][k]&ok[k][i]).count();
					ans+=c*a;
				//	printf("%d %d %d %d %d %d\n",i,j,k,a,b,c);
				}
			}
		}
		for(int j =0;j<n;j++)
			for(int k = 0;k<n;k++)
				ok[j][k][i]=0;
	}
	printf("%lld\n",ans);
//	printf("%lld\n",ans/15);
}