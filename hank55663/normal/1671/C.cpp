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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
	int n,x;
	scanf("%d %d",&n,&x);
	int a[200005];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	LL sum=0;
	for(int i= 0;i<n;i++){
		sum+=a[i];
	}
	LL ans=0;
	int last=-1;
	for(int i = n-1;i>=0;i--){
		if(sum<=x){
			LL tot=(x-sum)/(i+1);
			ans+=(i+1)*(tot-last);
			last=tot;
		}
		sum-=a[i];
	}
	printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/