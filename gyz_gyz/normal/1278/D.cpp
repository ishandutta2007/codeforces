#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int inf=1e9;
const int N=5e5+10;
struct pr{
	int l,r,id;
	friend bool operator<(const pr&a,const pr&b){return a.r<b.r;}
}a[N];
int f[N];
int gf(int x){return x==f[x]?f[x]:f[x]=gf(f[x]);}
bool cmp(const pr&a,const pr&b){return a.l<b.l;}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1,cmp);set<pr>s;
	rep(i,1,n){
		a[i].id=i;f[i]=i;
		for(auto j=s.lower_bound({0,a[i].l,0});j!=s.end()&&j->r<a[i].r;++j){
			int x=gf(i),y=gf(j->id);
			if(x==y){
				printf("NO\n");return 0;
			}
			f[x]=y;
		}
		s.insert(a[i]);
	}int cnt=0;
	rep(i,1,n)if(f[i]==i)++cnt;
	printf("%s\n",cnt==1?"YES":"NO");
}