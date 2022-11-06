#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=998244353;
int a[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)a[i]=0;
	rep(i,1,n){int x;
		scanf("%d",&x);++a[x];
	}
	int x=n,ans=0,s=0;
	sort(a+1,a+n+1,[](int&a,int&b){return a>b;});
	rep(i,1,n){
		while(s&&x>a[i]){
			ans+=x;--x;--s;
		}
		x=min(x,a[i]);++s;
	}
	while(x&&s){
		ans+=x;--x;--s;
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}