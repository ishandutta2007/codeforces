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
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[5005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	a[n]=0;
	LL Min = 0;
	LL x=n,y=n,z=n;
	LL now = 0; 
	for(int i=n;i>=0;i--){
		now+=a[i];
		LL tot=0;
		LL ind=-1;
		LL Ma=0;
		for(int j=0;j<i;j++){
			tot+=a[j];
			if(Ma<tot){ 
				Ma=max(Ma,tot);
				ind=j;
			}
		//	printf("%d %d %lld\n",i,j,tot-Ma+now);
			if(Min>tot-Ma+now){
				Min=min(Min,tot-Ma+now);
				z=i;
				y=j+1;
				x=ind+1;
			}
		}
	}
	printf("%lld %lld %lld\n",x,y,z);
}