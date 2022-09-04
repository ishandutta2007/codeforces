#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define Max(a,b,c) max(a,max(b,c))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
#define pmm pair<map<int,int>*,map<int,LL>*>
typedef long long LL;
using namespace std;
const LL mod=1e9+7;
bool isprime[40000000];
vector<LL> factor;
vector<LL> factor2;
int main(){
 	LL n;
	int k;
	scanf("%I64d %d",&n,&k);
	for(LL i=1;i<=sqrt(n);i++)
	if(n%i==0){
		factor.pb(i);
		if(n/i!=i)
		factor2.pb(n/i);
	}	
	if(factor.size()+factor2.size()<k)
	printf("-1");
	else{
		if(factor.size()>=k){
			printf("%I64d\n",factor[k-1]);
		}
		else{
			k-=factor.size();
			vector<LL>::iterator it=factor2.end();
			//printf("%d",k);
			printf("%I64d\n",*(it-k));
		}
	}
}