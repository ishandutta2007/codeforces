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
#define index Index
using namespace std;
typedef long long LL;
vector<int> prime;
bool isprime[20005];
void find(){
	MEM(isprime);
	for(int i=2;i<20000;i++){
		if(!isprime[i]){
			prime.pb(i);
			for(int j=i*2;j<20000;j+=i)
				isprime[j]=1;
		}
	}
}
void cal(int l){
	MEM(isprime);
	for(auto it:prime){
		int x=l/it;
		for(int i=x*it;i<l+20000;i+=it){
			if(i>=l){
				isprime[i-l]=1;
			}
		}
	}
}
int main(){
	unsigned int n,a,b,c,d;
	scanf("%u %u %u %u %u",&n,&a,&b,&c,&d);
	find();
	int l=0,r=20000;
	unsigned int ans=0;
	for(unsigned int i=2;i<=n;i++){
		if(i>=r){
			cal(r);
			l=r;
			r=l+20000;
		}
		if(!isprime[i-l]){
			unsigned int k=n;
			unsigned int tot=0;
			while(k){
				k/=i;
				tot+=k;
			}
			ans+= (i*i*i*a+i*i*b+i*c+d)*tot;
		}
	}
	printf("%u\n",ans);
}