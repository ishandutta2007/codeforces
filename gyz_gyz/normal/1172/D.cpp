#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int a[N],b[N],p[N],q[N];
int main(){int n;
	scanf("%d",&n);
	vector<pair<pair<int,int>,pair<int,int>>>v;
	rep(i,1,n){
		scanf("%d",&a[i]);p[a[i]]=i;
	}
	rep(i,1,n){
		scanf("%d",&b[i]);q[b[i]]=i;
	}
	rep(i,1,n){
		int x=p[i],y=q[i];
		if(x!=i||y!=i){
			v.pb({{x,i},{i,y}});
			swap(p[a[i]],p[a[x]]);
			swap(a[i],a[x]);
			swap(q[b[i]],q[b[y]]);
			swap(b[i],b[y]);
		}
	}
	cout<<v.size()<<endl;
	for(auto i:v)printf("%d %d %d %d\n",i.fr.fr,i.fr.sc,i.sc.fr,i.sc.sc);
}