#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
long long x[210000];
long long y[210000];
pair<long long,long long>p[210000];
int bit[210000];
int sum(int a,int b){
	if(a>b)return 0;
	if(a)return sum(0,b)-sum(0,a-1);
	int ret=0;
	for(;b>=0;b=(b&(b+1))-1)ret+=bit[b];
	return ret;
}
void add(int a,int b){
	for(;a<210000;a|=a+1)bit[a]+=b;
}

int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%lld%lld",x+i,y+i);
		p[i]=make_pair(-y[i],x[i]);
	}
	std::sort(p,p+a);
	std::sort(x,x+a);
	long long ret=0;
	long long act=0;
	int L=mod;
	int R=-1;
	vector<int>zz;
	for(int i=0;i<a;i++){
		long long X=p[i].second;
		long long Y=p[i].first;
		int zh=lower_bound(x,x+a,X)-x;
		L=min(L,zh);
		R=max(R,zh);
		if(sum(zh,zh)==0){
			act++;
			add(zh,1);
		}
		zz.push_back(zh);

		if(i==a-1||p[i].first!=p[i+1].first){
			zz.push_back(-1);
			zz.push_back(205000);
			std::sort(zz.begin(),zz.end());

			ret+=(act+1)*act/2;
			for(int j=0;j+1<zz.size();j++){
				long long tmp=sum(zz[j]+1,zz[j+1]-1);
				ret-=tmp*(tmp+1)/2;
			}
			zz.clear();
		}
	}
	printf("%lld\n",ret);
}