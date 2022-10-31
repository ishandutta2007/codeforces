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
const long double EPS=1e-13;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
long long x[510000];
int L[510000];
int R[510000];
long long v[510000];
pair<long long,int> z[510000];
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int UF[510000];
int FIND(int a){
	if(UF[a]<0)return a;
	return UF[a]=FIND(UF[a]);
}
void UNION(int a,int b){
	a=FIND(a);b=FIND(b);if(a==b)return;UF[a]+=UF[b];UF[b]=a;
}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++){
		scanf("%I64d",x+i);
	}
	for(int i=0;i<b;i++){
		scanf("%d%d",L+i,R+i);
		L[i]--;R[i]--;
		v[i]=(x[L[i]]^x[R[i]]);
		z[i]=make_pair(v[i],i);
	}
	long long tot=1LL<<c;
	std::sort(z,z+b);
	for(int i=0;i<a;i++)UF[i]=-1;
	long long ret=0;
	for(int i=0;i<b;i++){
		if(i&&z[i].first==z[i-1].first)continue;
		set<int>S;
		tot--;
		int rk=0;
		for(int j=i;z[i].first==z[j].first;j++){
			if(FIND(L[z[j].second])!=FIND(R[z[j].second])){
				UNION(L[z[j].second],R[z[j].second]);
				rk++;
			}
			S.insert(L[z[j].second]);
			S.insert(R[z[j].second]);
		}
		int cnt=S.size();
		ret=(ret+pw(2,a-rk))%mod;
		for(set<int>::iterator it=S.begin();it!=S.end();it++){
			UF[*it]=-1;
		}
	}
	ret=(ret+tot%mod*pw(2,a))%mod;
	printf("%I64d\n",ret);
}