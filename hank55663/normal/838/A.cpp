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
#define hash Hash
using namespace std;
typedef long long LL;
vector<int> prime;
void find(){
	prime.pb(1);
	int isprime[2500];
	MEM(isprime);
	for(int i=2;i<2500;i++){
		if(!isprime[i]){
			prime.pb(i);
			for(int j=i;j<2500;j+=i)
			isprime[j]=1;
		}
	}
} 
char c[5005][5005];
int main(){
	find();
	int n,m;
	scanf("%d %d",&n,&m);
	MEM(c);
	for(int i=0;i<n;i++)
	scanf("%s",c[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		c[i][j]-='0';
	//printf("%d\n",prime.size());
	int lastunitx=0,lastunity=0;
	int ans=0;
	for(int i=0;i<max(n,m);i++)
		for(int j=0;j<max(n,m);j++){
			if(c[i][j]==1)
			ans++;
		}
	ans=min(ans,max(n,m)*max(n,m)-ans);
	for(int i=1;prime[i]<max(n,m);i++){
		int unitx=prime[i],unity=prime[i];
		int temp=0;
		for(int j=0;j<n;j+=unitx)
			for(int k=0;k<m;k+=unity){
				int sum=0;
				for(int x=0;x<unitx;x++){
					if(j+x==n){
						sum+=(unitx-x)*unity;
						break;
					}
					for(int y=0;y<unity;y++){
						if(k+y==m){
							sum+=unity-y;
							break;
						}
						if(c[j+x][k+y]==0)
						sum++;
					}
				}
				sum=min(sum,unitx*unity-sum);
				temp+=sum;
			}
		ans=min(temp,ans);
	}
	printf("%d\n",ans);
}