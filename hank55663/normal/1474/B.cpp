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
int Isprime[1000005];
bool solve(){
	int d;
	scanf("%d",&d);
	LL now=d+1;
	while(!Isprime[now])now++;
	LL now2=now+d;
	while(!Isprime[now2])now2++;
	LL ans=min(now*now*now,now*now2);
	printf("%lld\n",ans);
    return true;
}
int main(){
	fill(Isprime,Isprime+1000005,1);
	for(int i = 2;i<1000005;i++){
		if(Isprime[i]){
			for(int j = i*2;j<1000005;j+=i)
				Isprime[j]=0;
		}
	}
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