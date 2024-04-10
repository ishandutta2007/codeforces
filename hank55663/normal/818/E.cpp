#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define EPS 1e-11
//#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define sqr(x) ((x)*(x))
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long LL;
int isprime[100005];
vector<int> prime;
void find(){
	MEM(isprime);
	for(int i=2;i<100005;i++){
		if(!isprime[i]){
			prime.pb(i);
			for(int j=i*2;j<100005;j+=i){
				isprime[j]=1;
			}
		}
	}
}
pii factor[12];
vector<int> v[12]; 
int main(){
	find();
	int n,k;
	scanf("%d %d",&n,&k);
	if(k==1)
	{
		printf("%I64d\n",(LL)n*(n+1)/2);
		return 0; 
	}
	int now=0;
	for(int i=0;i<prime.size();i++){
		if(k%prime[i]==0){
			factor[now].x=prime[i];
			factor[now].y=0;
			while(k%prime[i]==0){
				factor[now].y++;
				k/=prime[i];
			}
			now++;
		}
	}
	if(k!=1)
	factor[now].x=k,factor[now].y=1,now++;
	for(int i=0;i<now;i++)
	v[i].pb(0);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
	//	printf("?");
		for(int j=0;j<now;j++){
			int ans=0;
			//printf(" ??");
			while(a%factor[j].x==0)
			ans++,a/=factor[j].x;
			v[j].pb(v[j].back()+ans);
		//	printf("%d ",v[j].back()); 
		}
	//	printf("\n");
	}
	LL ans=0;
	for(int i=n;i>=1;i--){
		int Min=1e9;
		for(int j=0;j<now;j++){
			Min=min(Min,(int)(upper_bound(v[j].begin(),v[j].end(),v[j][i]-factor[j].y)-v[j].begin()));
		}
		ans+=Min;
	}
	printf("%I64d\n",ans);
}
//Axyz=xy+yz+zx
// Y k  
// S k+y|k+y+a
//P k+p/k+p+b
// S k+p+s+0~2=k+y+0~1
// 3*k+y+p+a+b=12+j