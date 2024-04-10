#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
int a[N];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	ll tot=0;int mx=0;
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		tot+=a[i];
		if(tot-max(a[mx],a[i])>m){
			printf("%d\n",mx);return;
		}
		if(a[i]>a[mx])mx=i;
	}
	printf("%d\n",tot<=m?0:mx);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}