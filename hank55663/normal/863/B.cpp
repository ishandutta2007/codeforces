#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i=0;i<2*n;i++)
	scanf("%d",&a[i]);
	sort(a,a+2*n);
	int ans=1e9;
	for(int i=0;i<2*n;i++)
		for(int j=i+1;j<2*n;j++){
			int res=0,last=0;
			for(int k=0;k<2*n;k++){
				if(k!=i&&k!=j){
					if(last){
						res+=a[k]-last;
						last=0;
					} 
					else{
						last=a[k];
					}
				}
			}
			ans=min(ans,res);
		}
	printf("%d\n",ans);
}