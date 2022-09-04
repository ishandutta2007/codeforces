#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define count Count
using namespace std;
typedef long long LL;
int isprime[1000005];
void find(){
	MEM(isprime);
	for(int i=2;i<1000005;i++){
		if(!isprime[i]){
			for(int j=i;j<1000005;j+=i)
			isprime[j]=i;
		}
	}
}
int pro[1000005];
int mod=1e9+7;
int count[1000005];
int main(){
	find();
	for(int i=2;i<1000005;i++){
		isprime[i]=isprime[i/isprime[i]]+1;
	}
	for(int i=2;i<1000005;i++){
		pro[i]=i;
	}
	for(int i=2;i<1000005;i++){
		for(int j=i*2;j<1000005;j+=i){
			pro[j]-=pro[i];
		}
	}
	int f[200005];
	int add=1;
	f[1]=1;
	for(int i=2;i<200005;i++){
		add=add*2%mod;
		f[i]=(f[i-1]*2%mod+add)%mod;
	}
//	int t=100;
//	while(t--){
		int n;
		scanf("%d",&n);
	//	n=2;
	//	int A[2];
	//	A[0]=rand()%1000000+1;
	//	A[1]=rand()%1000000+1;
		//map<int,map<int,int> > m;
		MEM(count);
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
		//	a=A[i];
			for(int j=1;j*j<=a;j++){
				if(a%j==0){
					count[j]++;
					count[a/j]++;
					if(a/j==j){
						count[j]--;
					}
				//	printf("%d %d\n",j,a/j);
				}
			/*	*/
			}
		}
		LL res=0;
		for(int i=2;i<=1000000;i++){
			if(count[i]){
				res+=(LL)f[count[i]]*pro[i];
	//			printf("%d %d\n",count[i],i);
			}
			res%=mod;
		}
	/* if(__gcd(A[0],A[1])==1){
			if(res!=A[0]+A[1])
			printf("%d %d 1 %d\n",A[0],A[1],A[0]+A[1]);
		}
		else{
			if(res!=A[0]+A[1]+__gcd(A[0],A[1])*2)
			printf("%d %d 2 %d\n",A[0],A[1],__gcd(A[0],A[1]));
		}
		*/
		printf("%I64d\n",res);
//	}
}
/*
1 1 1           1
2 2 1 + 1 2     4
3 3 1 + 3 2 + 1 3  12
  4 1 + 6 2 +4 3 +1 4
*/