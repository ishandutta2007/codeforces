#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int prime[1000005];
void find(){
	MEM(prime);
	for(int i=2;i<1000005;i++)
	if(!prime[i]){
		for(int j=i*2;j<1000005;j+=i)
		prime[j]=1;
	}
}
int dis(int s,int t,int k,int n){
	if(t==n){
		return t-s-1+k;
	}
	return t-s;
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int k;
	find();
	prime[1]=1;
	for(k=1;;k++){
		if(!prime[k+n-2])
		break;
	} 
	printf("%d %d\n",k+n-2,k+n-2);
	for(int i=1;i<n;i++){
		m--;
		printf("%d %d %d\n",i,i+1,dis(i,i+1,k,n));
	}
	for(int i=1;i<n;i++){
		for(int j=i+2;j<=n;j++){
			if(!m)
			break;
			printf("%d %d %d\n",i,j,dis(i,j,k,n));
			m--;
		}
	} 
	
}