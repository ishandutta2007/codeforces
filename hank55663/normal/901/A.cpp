#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int h;
	scanf("%d",&h);
	int a[200000];
	for(int i=0;i<=h;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<h;i++){
	//	printf("%d\n",a[i]);
	if(a[i]>=2&&a[i+1]>=2){
		printf("ambiguous\n");	
		int last=0;
		for(int j=0;j<=h;j++){
			for(int k=0;k<a[j];k++){
				printf("%d ",last);
			}
			last+=a[j];
		}
		last=0;
		printf("\n");
		for(int j=0;j<=h;j++){
			for(int k=0;k<a[j];k++){
				if(j==i+1&&k==0)
				printf("%d ",last-1);
				else
				printf("%d ",last);
			}
			last+=a[j];
		}
		printf("\n");
		return 0;
	}
	}
	printf("perfect\n");
}