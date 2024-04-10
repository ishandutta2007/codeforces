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
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int f=n,t=n*2;
	int a[100005];
	for(int i=0;i<k;i++){
		scanf("%d",&a[i]);
		f-=a[i]/4;
		a[i]%=4;
		if(f<0){
			a[i]+=-f*4;
			f=0;
		}
		t-=a[i]/2;
		a[i]%=2;
		if(t<0){
			a[i]+=-t*2;
			t=0;
		}
		//printf("%d ",a[i]);
	}
	int o=0,tw=0,th=0;
	for(int i=0;i<k;i++){
		if(a[i]==1)
		o++;
		if(a[i]==2)
		tw++;
		if(a[i]==3)
		th++;
	}
	//printf("%d %d %d %d %d\n",o,tw,th,f,t);
	while(f&&th){
		f--;
		th--;
	}
	while(t&&o){
		t--;
		o--;
	}
	while(tw&&f){
		tw--;
		o--;
		f--;
	}
	while(f&&o){
		o-=2;
		f--;
	}
	if(o>0||tw*2+o>0||th*3+tw*2+o>0){
		printf("NO\n");
	}
	else
	printf("YES\n");
}