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
#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define right RRR
#define left LLL
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long LL;
int mod =1e9+7;
LL f_pow(int a,int b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp = temp *temp %mod;
		b>>=1;
	} 
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	LL a[200005];
	for(int i=0;i<n;i++)
	scanf("%I64d",&a[i]);
	int flag=1;
	for(;n%4!=1;n--){
		for(int i=0;i<n-1;i++){
			a[i]=a[i]+a[i+1]*flag;
			a[i]=(a[i]%mod+mod)%mod;
			flag*=-1;
		}
	}
	int num=n/2,hi=1;
	LL now=1;
	LL ans=0;
	for(int i=0;i<n;i+=2){
		ans+=now*a[i]%mod;
	//	printf("%I64d %d\n",now,a[i]);
		ans%=mod;
		now=now*num%mod*f_pow(hi,mod-2)%mod;
		num--;
		hi++;
	}
	printf("%I64d\n",ans);
	
}