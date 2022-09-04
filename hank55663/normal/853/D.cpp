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
int a[300005];
int n;
int cal(int x){
	int Max=n+1,Min=-1;
	int res=1e9;
	while(Max>Min+1){
		int mid=(Max+Min)/2;
		int cop=0;
		int sp=0;
		for(int i=0;i<n;i++){
			if(a[i]==1000){
				if(i>mid)
				{
					if(cop>=1000){
						cop-=1000;
					}
					else{
						sp+=1000-cop;
						cop=0;
					}
				}
				else{
					sp+=1000;
					cop+=100;
				}
			}
			else{
				if(i>x){
					if(cop>=2000){
						cop-=2000;
					}
					else{
						sp+=2000-cop;
						cop=0;
					}
				}
				else{
					sp+=2000;
					cop+=200;
				}
			}
		}
		res=min(res,sp);
		if(cop>0){
			Max=mid;
		}
		else{
			Min=mid;
		}
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int Max=n,Min=-1;
	while(Max>Min+2){
		int mid1=(Max*2+Min)/3,mid2=(Max+Min*2)/3;
		if(cal(mid1)>cal(mid2)){
			Max=mid1;
		}
		else{
			Min=mid2;
		}
	}
	int ans=1e9;
	for(int i=Min;i<=Max;i++)
	ans=min(cal(i),ans);
	printf("%d\n",ans);
}
/*
2 3
0 1
*/