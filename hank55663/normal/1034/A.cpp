#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
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
int isprime[15000005];
void Find(){
	MEM(isprime);
	for(int i=2;i<=15000000;i++){
		if(isprime[i]==0){
			for(int j=i;j<=15000000;j+=i){
				isprime[j]=i;
			}
		}
	}
}
map<int,int> m;
int main(){
	int n;
	scanf("%d",&n);
	int gcd;
	int a[300005];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	gcd=a[0];
	for(int i=1;i<n;i++){
		gcd=__gcd(a[i],gcd);
	}
	for(int i=0;i<n;i++){
		a[i]/=gcd;
	}
	Find();
	for(int i=0;i<n;i++){
		vector<int> v;
		int k=a[i];
		while(k!=1){
			v.pb(isprime[k]);
			k/=isprime[k];
			//printf("%d ",isprime[k]);
		}
		//printf("\n");
		sort(v.begin(),v.end());
		if(!v.empty()){
			m[v[0]]++;
			for(int j=1;j<v.size();j++){
				if(v[j]!=v[j-1]){
					m[v[j]]++;
				}
			}
		}
	}
	int Max=0;
	for(auto it:m)
	Max=max(it.y,Max);
	if(Max==0)
	printf("-1\n");
	else
	printf("%d\n",n-Max);
}