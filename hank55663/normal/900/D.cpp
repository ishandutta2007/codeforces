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
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int mod=1e9+7;
LL f_pow(int a,int b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
LL dfs(int i,vector<int> &v,int sum,int x){
	if(i==v.size()){
		if(sum%2==0)
		return f_pow(2,x-1);
		else
		return -f_pow(2,x-1);
	}
	return (dfs(i+1,v,sum+1,x/v[i])+dfs(i+1,v,sum,x))%mod;
}
int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	if(y%x!=0){
		printf("0\n");
	} 
	else{
	//	printf("?\n");
		int k=y/x;
		vector<int> prime;
		y=k;
		for(int i=2;i<=sqrt(y);i++){
			if(y%i==0){
				prime.pb(i);
				while(y%i==0)y/=i;
			}
		}
		if(y!=1)
		prime.pb(y);
		
		printf("%I64d\n",(dfs(0,prime,0,k)+mod)%mod);
	}
}