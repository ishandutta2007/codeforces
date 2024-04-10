//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		LL p,q,x,y;
		scanf("%I64d %I64d %I64d %I64d",&x,&y,&p,&q);
		LL xxx=x,yyy=y;
		LL gcd=__gcd(p,q);
		p/=gcd;
		q/=gcd;
		if(q==0){
			printf("-1\n");
		}
		else if(p==q&&x!=y){
			printf("-1\n");
		}
		else if(p==q){
			printf("0\n");
		} 
		else if(p==0&&x!=0){
			printf("-1\n"); 
		} 
		else if(p==0){
			printf("0\n");
		}
		else{
			LL a=(x*q-p*y)/(p-q);
			if((x*q-p*y)%(p-q)!=0)
			a++;
			if(a<0)
			a=0;
			LL ans=a; 
			x+=a,y+=a;
			ans+=(p-x%p)%p;
			y+=(p-x%p)%p;
			x+=(p-x%p)%p;
		//	printf("%I64d\n",ans);
			LL xx=ans; 
		//	printf("%I64d\n",ans);
			ans+=x/p*q-y;
		//	printf("%I64d %I64d\n",x/p*q,y);
			assert(x/p*q>=y);
			LL gg=__gcd(x,x/p*q);
		//	assert((x/gg!=p&&x/p*q/gg==q);
			assert((yyy+ans)%q==0); 
			assert((yyy+ans)/q*p>=xxx&&(yyy+ans)/q*p-xxx<=ans);
			assert(x/p*q-yyy>=0);
			while(x/p*q-yyy>=x-xxx&&x/p*q-yyy>=0&&x-xxx>=0)
			x-=p;
			x+=p;
			printf("%I64d\n",x/p*q-yyy);
		} 
	}
}