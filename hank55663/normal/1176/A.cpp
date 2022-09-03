#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		LL n;
		scanf("%lld",&n);
		LL cnt2=0,cnt3=0,cnt5=0;
		while(n%2==0){
			n/=2;
			cnt2++;
		}
		while(n%3==0){
			n/=3;
			cnt3++;
		}
		while(n%5==0){
			n/=5;
			cnt5++;
		}
		if(n!=1){
			printf("-1\n");
		}
		else{
			printf("%lld\n",cnt2+cnt3*2+cnt5*3);
		}
	}
}
/*
aaaa
aaba
abaa
baaa
baba
*/