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
	LL x;
	scanf("%lld",&x);
	vector<LL> v;
	for(LL i =1;i*i*i<=x;i++){
		v.pb(i*i*i);
	}
	v.pb(x+1);
	for(LL i = 1;i*i*i<=x;i++){
		if(*lower_bound(v.begin(),v.end(),x-i*i*i)==x-i*i*i){
			printf("Yes\n");return true;
		}
	}
	printf("NO\n");
	return true;
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}