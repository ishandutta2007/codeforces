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
	int p[105];
	LL sum=0;
	for(int i = 0;i<n;i++){
		scanf("%d",&p[i]);
	}
	LL Max=1e15,Min=-1;
	while(Max>Min+1){
		LL mid=(Max+Min)/2;
		LL sum=p[0]+mid;
		int ok=1;
		for(int i = 1;i<n;i++){
			LL x=sum*k/100;
			if(x<p[i]){
				ok=0;
				break;
			}
			sum+=p[i];
		}
		if(ok)Max=mid;
		else Min=mid;
	}
	printf("%lld\n",Max);
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/