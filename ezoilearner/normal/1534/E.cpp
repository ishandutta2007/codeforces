#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

int n,K;
#define Maxn 505
int a[Maxn];

int mn=-1;

void check(int t){
	if((K*t%2)!=(n%2))return;
	int a=(t-1)/2*n,b=(K*t-n)/2;
	if(a<b&&K==n)return;
	while(a<b){
		t+=2;
		a+=n;b+=K;
	}
	if(mn==-1)mn=t;else mn=min(mn,t);
}

vector<int> vec[Maxn];

int main(){
	scanf("%d%d",&n,&K);
	int z=(n+K-1)/K;
	check(z);check(z+1);
	if(mn==-1){
		puts("-1");
		return 0;
	}
	int re=(K*mn-n)/2;
	rep(i,1,n){
		a[i]=1;
		while(a[i]+2<=mn&&re){
			re--;
			a[i]+=2;
		}
	}
	int at=0;
	rep(i,1,n){
		rep(j,1,a[i]){
			vec[at].push_back(i);
			at=(at+1)%mn;
		}
	}
	int res=0;
	rep(i,0,mn-1){
		printf("? ");
		for(int j=0;j<vec[i].size();++j)printf("%d ",vec[i][j]);
		fflush(stdout);
		int x;
		scanf("%d",&x);
		res^=x;
	}
	printf("! %d\n",res);fflush(stdout);
	return 0;
}