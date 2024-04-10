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
int isprime[1000005];
int find(){
	MEM(isprime);
	for(int i=2;i<=1e6;i++) {
		if(!isprime[i]){
			prime.pb(i);
			for(int j=i*2;j<=1e6;j+=i)
			isprime[j]=1;
		}
	}
}
set<LL> target;
map<LL,int> m;
LL f(LL a,LL b){
	if(b==0)
	return 0;
	if(a==1)
	return b;
	LL sum=1e12;
	for(map<LL,int>::iterator it=m.begin();it!=m.end();it++){
		if(b%it->x<sum){
			target.clear();
			sum=b%it->x;
			target.insert(it->x);
		}
		else if(b%it->x==sum){
			target.insert(it->x);
		}
	}
	LL gcd=__gcd(a,b-sum); 
	LL k=gcd;
	for(set<LL>::iterator it=target.begin();it!=target.end();it++){
		int tot=0;
		while(gcd%*it==0)
		{
			tot++;
			gcd/=*it;
		}
		m[*it]-=tot;
		if(m[*it]==0)
		m.erase(*it);
	}
//	printf("%d",sum);
	return f(a/k,(b-sum)/k)+sum;
}
int main()
{
	find();
	LL a,b;//=2ll*3*5*7*11*13*17*19*23*29*31,b=a-1;
	scanf("%I64d %I64d",&a,&b);
	LL k=a;
	for(int i=0;i<prime.size();i++){
		while(a%prime[i]==0){
			m[prime[i]]++;
			a/=prime[i];
		}
	}
	if(a!=1)
	m[a]++;
	printf("%I64d\n",f(k,b));
}