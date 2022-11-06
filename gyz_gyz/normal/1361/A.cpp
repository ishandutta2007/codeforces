#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
pii a[N];vector<int>p[N];int s[N];bool v[N];
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	rep(i,1,n){
		scanf("%d",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	rep(i,1,n){
		int x=a[i].sc;
		int e=p[x].size();
		rep(j,1,e+1)v[j]=0;
		for(auto&j:p[x])v[s[j]]=1;
		rep(j,1,e+1)if(!v[j]){
			s[x]=j;break;
		}
		if(s[x]!=a[i].fr){
			printf("-1\n");return 0;
		}
	}
	rep(i,1,n)printf("%d%c",a[i].sc,i==n?'\n':' ');
}