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
#define index Index
using namespace std;
bool solve(){
	int n;
	scanf("%d",&n);
	int a[105];
	int cnt[105];
	MEM(cnt);
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i = 0;i<=100;i++){
		if(cnt[i]){
			printf("%d ",i);
			cnt[i]--;
		}
	}
	for(int i = 0;i<=100;i++){
		while(cnt[i]){
			printf("%d ",i);
			cnt[i]--;
		}
	}
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}