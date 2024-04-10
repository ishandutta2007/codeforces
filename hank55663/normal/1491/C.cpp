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
	int n;
	scanf("%d",&n);
	int s[5005];
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	LL Max=1e15,Min=-1;
	while(Max>Min+1){
		LL mid=(Max+Min)/2;
		LL val[5005];
		int ok=1;
		fill(val,val+5005,0);
		val[1]+=mid;
		val[2]-=mid;
		LL now=0;
		//if(mid==4){
			//for(int i = 1;i<=n;i++)printf("%d ",val[i]);
	//		//printf("\n");
	//	}
		for(int i = 1;i<=n;i++){
		//if(mid==3)printf("%d ",now+val[i]);
			now+=val[i];
			if(now<s[i]-1){
				ok=0;
				break;
			}
			if(now==s[i]-1){
				if(now){
					val[i+2]++;
					val[min(i+s[i]+1,n+1)]--;
				}
			}
			else{
			val[i+1]++;
			val[min(i+s[i]+1,n+1)]--;
			val[i+1]+=now-s[i];
			val[i+2]-=now-s[i];
			}
		//	if(mid==3){
			//	printf("%d\n",now-s[i]);
			//for(int i = 1;i<=n;i++)printf("%d ",val[i]);
			//	printf("\n");
			//}
		}
		if(ok)Max=mid;
		else Min=mid;
	}
	printf("%lld\n",Max);
}
int main(){
		//MEMS(dp);
	int t=1;//000000;//000000;
    scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}