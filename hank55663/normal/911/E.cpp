#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[200005];
	int ans[200005];
	for(int i=0;i<k;i++)
	scanf("%d",&a[i]),ans[i]=a[i];
	vector<int> v;
	v.pb(1e9);
	int now=1;
	set<int> s;
	for(int i=1;i<=n;i++)s.insert(i);
	for(int i=0;i<k;i++){
		if(v.back()<a[i]){
			printf("-1\n");
			return 0;
		}
		v.pb(a[i]);
		s.erase(a[i]); 
		while(v.back()==now)
		v.pop_back(),now++;
	}
	for(int i=k;i<n;i++){
		auto it=s.upper_bound(v.back());
		it--;
		v.pb(*it);
		ans[i]=*it;
		s.erase(it);
		while(v.back()==now)
		v.pop_back(),now++;
	}
	for(int i=0;i<n;i++)
	printf("%d ",ans[i]);
}