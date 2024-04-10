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
void solve(){
	int n;
	scanf("%d",&n);
	LL Max=1e9,Min=1;
	while(Max>Min+2){
		LL mid=(Max+Min)/2;
		if(mid%2==0)mid++;
		if(mid*mid/2+1>n)Max=mid;
		else Min=mid;
	}
	printf("%lld\n",Min/2);
}
int main(){
    int t=1;00000;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 2 3 4 5 6 7
1 3 5 7 2 4 6
0 3 6 2 5 1 4
*/