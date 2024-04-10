#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a==b){
		printf("0\n");
		return 0;
	}
	int sum=abs(a-b);
	LL ans=1e18,ansk=1e18;
	for(int i = 1;i*i<=sum;i++){
		if(sum%i==0){
			LL aa=i;
			LL x=(aa-a%aa)%aa+a,y=(aa-b%aa)%aa+b;
			LL tot=x*y/__gcd(x,y);
			LL add=(aa-a%aa)%aa;
			//printf("%lld %lld %lld\n",aa,tot,add);
			if(tot<ans){
				ans=tot;
				ansk=add;
			}
			if(tot==ans){
				ansk=min(ansk,add);
			}
			aa=sum/i;
			x=(aa-a%aa)%aa+a,y=(aa-b%aa)%aa+b;
			tot=x*y/__gcd(x,y);
			add=(aa-a%aa)%aa;
		//	printf("%lld %lld %lld\n",aa,tot,add);
			if(tot<ans){
				ans=tot;
				ansk=add;
			}
			if(tot==ans){
				ansk=min(ansk,add);
			}
		}
	}
	printf("%lld\n",ansk);
}