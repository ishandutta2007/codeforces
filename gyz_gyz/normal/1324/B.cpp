#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
int a[N];bool v[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n){
		rep(j,1,n)v[j]=0;
		dep(j,i-1,1)v[a[j]]=1;
		rep(j,i+1,n)if(v[a[j]]){
			printf("YES\n");return;
		}
	}
	printf("NO\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}