#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
struct pt{ll x,y;};
bool operator <(pt x,pt y){
	if(x.x==y.x)return x.y<y.y;return x.x<y.x;
}
int n,op,tot;ll x,y,z,X,Y,Z;
ll gcd(ll x,ll y){
	if(!x)return y;return gcd(y%x,x);
}
map<ll,set<pt>>a;map<pt,int>b;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%I64d%I64d",&op,&x,&y);
		if(op==1){tot++;
			z=gcd(x,y);b[{x/z,y/z}]++;z=x*x+y*y;
			for(auto i:a[z]){
				X=x+i.x;Y=y+i.y;Z=gcd(X,Y);b[{X/Z,Y/Z}]+=2;
			}a[z].insert({x,y});
		}
		if(op==2){tot--;
			z=gcd(x,y);b[{x/z,y/z}]--;z=x*x+y*y;
			a[z].erase(a[z].lower_bound({x,y}));
			for(auto i:a[z]){
				X=x+i.x;Y=y+i.y;Z=gcd(X,Y);b[{X/Z,Y/Z}]-=2;
			}
		}
		if(op==3){
			z=gcd(x,y);
			if(b.count({x/z,y/z}))printf("%d\n",tot-b[{x/z,y/z}]);
			else printf("%d\n",tot);
		}
	}
}