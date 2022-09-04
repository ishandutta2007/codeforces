#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
using namespace std;
typedef long long LL;
int main(){
	LL n,h;
	scanf("%lld %lld",&n,&h);
	LL sum=(1+h)*h;
	if(sum%h==0&&sum/2<=n){
		sum/=2;
		n-=sum;
		n+=h;
		LL Max=2e9,Min=0;
		while(Max>Min+1){
			LL mid=(Max+Min)/2;
			LL sum=h*mid;
			if(sum%mid!=0){
				Max=mid;
			}
			else{
				LL x=mid-2;
				LL add;
				if(x%2==0){
					add=x*x/4+x/2;
				}
				else{
					x++;
					add=x*x/4;
				}
				if(sum+add>=n){
					Max=mid;
				}
				else{
					Min=mid;
				}
			}
		}
		printf("%lld\n",Min+h);
	}
	else{
		LL Max=2e9,Min=0;
		while(Max>Min+1){
			LL mid=(Max+Min)/2;
			if(mid*(mid+1)/2>=n){
				Max=mid;
			}
			else{
				Min=mid;
			}
		}
		printf("%lld\n",Max);
	}
}