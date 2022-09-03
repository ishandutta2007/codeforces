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
	int n,u,v;
	scanf("%d %d %d",&n,&u,&v);
	int a[105];
	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
	int same=1;
	for(int i = 0;i<n;i++){
		if(a[i]!=a[0])same=0;
	}
	if(same){
		printf("%d\n",v+min(u,v));
	}
	else{
		int same=1;
		for(int i = 0;i<n-1;i++){
			if(abs(a[i]-a[i+1])>1)same=0;
		}
		if(same){
			printf("%d\n",min(u,v));
		}
		else{
			printf("0\n");
		}
	}
}
int main(){
		//MEMS(dp);
	int t=1;//000000;//000000;
    scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}