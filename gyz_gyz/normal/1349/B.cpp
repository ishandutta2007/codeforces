#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int inf=1e9;
const int mo=1e9+7;
int b[N],w[N];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&w[i]);bool fl=0;
	rep(i,1,n)if(w[i]==m)fl=1;
	if(!fl){
		printf("no\n");return;
	}
	if(n==1){
		printf("yes\n");return;
	}int mx=0;
	b[1]=(w[1]<m)*2;
	rep(i,2,n){
		b[i]=b[i-1]+(w[i]<m)*2;
		if(b[i]-i<mx){
			printf("yes\n");return;
		}
		mx=max(mx,b[i-1]-(i-1));
	}
	printf("no\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}