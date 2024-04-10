#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 100005
int main(){
	LL a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	LL ans=b*2;
	if(a&&d){
		ans+=c*2;
	}
	ans+=min(a,d)*4;
	printf("%d\n",ans==(a+b+c+d)*2);
}