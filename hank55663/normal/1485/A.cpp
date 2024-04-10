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
	int a,b;
	scanf("%d %d",&a,&b);
	LL tmpa=a,tmpb=b;
	int tot=0;
	if(b!=1){
		while(tmpa){
			tot++;
			tmpa/=tmpb;
		}
	}
	else{
		tot=1e9;
	}
	if(b>a){
		printf("1\n");
		return true;
	}
	else{
		tot=min(tot,a-b+2);
	}
	for(int i = b+1;i*i<=a||i<=b+50000;i++){
		int tmp=a;
		int cnt=0;
		while(tmp){
			cnt++;
			tmp/=i;
		}	
		tot=min(tot,cnt+i-b);
	}
	printf("%d\n",tot);
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}