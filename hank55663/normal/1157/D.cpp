/*#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;*/
#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
LL f_pow(int x,int y){
	LL res=1,temp=x;
	while(y){
		if(y&1)res=res*temp;
		temp=temp*temp;
		y>>=1;
		if(res>2e9)
		res=2e9;
		if(temp>2e9)
		temp=2e9;
	}
	return res;
}
int main() {
	LL n,k;
	scanf("%lld %lld",&k,&n);
	LL st=0;
	st = (k-1)/(f_pow(2,n)-1)+1;
	/*for(LL i =1;n*(i+i+n-1)/2<=k;i++){
		//printf("%lld\n",(f_pow(2,n)-1)*(f_pow(2,(i-1))));
		printf("%lld\n",(f_pow(2,n)-1)*i);
		if((f_pow(2,n)-1)*i>=k){
			st=i;
			break;
		}
	}*/
	LL a[100005];
	LL sum=0;
	for(int i = 1;i<=n;i++){
		a[i]=st+i-1;
		sum+=st+i-1;
	}
	k-=sum;
	if(k<0){
		printf("NO\n");
		return 0;
	}
	LL add=0;
	a[0]=1e9;
	for(int i =2;i<=n;i++){
		while(a[i]+add<2*a[i-1]){
			int ad=n-i+1;
			if(k>=ad){
				k-=ad;
				add++;
			}
			else{
				break;
			}
		}
		a[i]+=add;
	}
		printf("YES\n");
		for(int i =1;i<=n;i++){
			printf("%lld ",a[i]);
		}
		printf("\n");
	return 0;
}
/*
0 1
1 1
2 1
3 2
4 2
5 2

6 3

*/
/*
 9 10 11
*/