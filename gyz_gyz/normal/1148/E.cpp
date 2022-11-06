#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=3e5+10;
const int mo=998244353;
int b[N];
int main(){int n;
	scanf("%d",&n);
	vector<pii>a;
	rep(i,1,n){int x;
		scanf("%d",&x);
		a.pb({x,i});
	}
	sort(a.begin(),a.end());
	rep(i,0,n-1)scanf("%d",&b[i]);
	sort(b,b+n);int x=0;vector<pair<pii,int>>v;
	rep(i,0,n-1){
		if(a[i].fr>b[i])return printf("NO\n"),0;
		if(a[i].fr==b[i])continue;
		while(a[i].fr<b[i]){
			while(x<n&&a[x].fr<=b[x])++x;
			if(x>=n)return printf("NO\n"),0;
			int d=min(b[i]-a[i].fr,a[x].fr-b[x]);
			v.pb({{a[i].sc,a[x].sc},d});
			a[i].fr+=d;a[x].fr-=d;
		}
	}
	printf("YES\n%d\n",(int)v.size());
	for(auto &i:v)printf("%d %d %d\n",i.fr.fr,i.fr.sc,i.sc);
}