#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define last Last
using namespace std;
typedef long long LL;
int main(){
	set<int> s;
	int n;
	scanf("%d",&n);
	LL a[200005];
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		s.insert(a[i]);
	}
	vector<int> v;
	for(int i=0;i<n;i++){
		for(int j=0;j<32;j++){
			vector<int> ans;
			ans.pb(a[i]);
			if(s.find(a[i]-(1ll<<j))!=s.end())
			ans.pb(a[i]-(1ll<<j));
			if(s.find(a[i]+(1ll<<j))!=s.end())
			ans.pb(a[i]+(1ll<<j));
			if(ans.size()>v.size())
			swap(ans,v);
		}
	}
	printf("%d\n",v.size());
	for(auto it:v)printf("%d ",it);
}