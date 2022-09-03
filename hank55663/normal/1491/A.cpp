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
	int n,q;
	scanf("%d %d",&n,&q);
	int a[100005];
	for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
	int cnt[2]={0,0};
	for(int i = 1;i<=n;i++)cnt[a[i]]++;
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x;
			scanf("%d",&x);
			cnt[a[x]]--;
			a[x]=1-a[x];
			cnt[a[x]]++;
		}
		else{
			int k;
			scanf("%d",&k);
			if(cnt[1]>=k)printf("1\n");
			else printf("0\n");
		}
	}
}
int main(){
		//MEMS(dp);
	int t=1;//000000;//000000;
    //scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}