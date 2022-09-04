#include<bits/stdc++.h>
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
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	LL n,r,k;
	scanf("%lld %lld %lld",&n,&r,&k);
	LL a[500005];
	for(int i=0;i<n;i++)
	scanf("%lld",&a[i]);
	LL Max=2e18,Min=0;
	while(Max>Min+1){
		LL temp[500005];
		for(int i=0;i<n;i++)
		temp[i]=a[i];
		LL mid=(Max+Min)/2;
		int L=0,R=-1;
		LL tot=0;
		LL less=k;
		for(int i=0;i<n;i++){
			while(R<i+r&&R<n-1)R++,tot+=temp[R];
			while(L<i-r)tot-=temp[L],L++;
			if(tot<mid){
				temp[R]+=mid-tot;
				less-=mid-tot;
				tot=mid;
			}
			if(less<0)
			break;
		}
	//	printf("%lld %lld\n",Max,Min);
		if(less<0)
		Max=mid;
		else
		Min=mid;
	}
	printf("%lld\n",Min);
}
/*
BC
ACC
AABC
CC
ABC
AACC*/