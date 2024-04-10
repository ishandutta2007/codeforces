#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=998244353;
const ll inf=1e18;
vector<int>p;int a[N];
int main(){int n;
	scanf("%d",&n);
	if(n==1){
		printf("0\n");return 0;
	}
	rep(i,1,n)scanf("%d",&a[i]);
	bool fl=1;
	rep(i,2,n)if(a[i]>a[i-1]){
		fl=0;
	}
	if(fl){
		printf("1\n%d",n);
		rep(i,1,n)printf(" 1");printf("\n");return 0;
	}
	printf("%d\n",n/2*2);
	rep(i,1,n/2*2){
		p.clear();int t=0;
		rep(j,1,n)if(j>1&&((a[j]<a[j-1])^(i&1))){
			p.push_back(t);
			rep(k,1,t/2)swap(a[j-t-1+k],a[j-k]);t=1;
		}else ++t;
		p.push_back(t);
		rep(k,1,t/2)swap(a[n-t+k],a[n-k+1]);
		rep(k,1,n/2)swap(a[k],a[n-k+1]);
		printf("%d",(int)p.size());
		for(auto&j:p)printf(" %d",j);
		printf("\n");
	}
}