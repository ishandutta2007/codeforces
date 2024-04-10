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
	int n,k;
	scanf("%d %d",&n,&k);
	int a[200005];
	for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
	int Min=1,Max=n+1;
	while(Max>Min+1){
		int mid=(Max+Min)/2;
		int pre[200005];
		pre[0]=0;
		int MMin=0;
		int ok=0;
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1];
			if(a[i]>=mid)pre[i]++;
			else pre[i]--;
			if(i>=k){
				if(pre[i]>MMin)ok=1;
				MMin=min(MMin,pre[i-k+1]);
			}
		}
	//	printf("%d %d\n",Min,Max);
		//getchar();
		if(ok){
			Min=mid;
		}
		else{
			Max=mid;
		}
	}
	printf("%d\n",Min);
	return true;
}
int main(){
	int t=1;//000000;
    //scanf("%d",&t);
    while(t--)solve();
}