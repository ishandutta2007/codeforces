#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool solve(){
	int n;
	scanf("%d",&n);
	map<int,int> m;
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		m[x]++;
	}
	vector<int> v;
	for(auto it:m)v.pb(it.y);
	sort(v.begin(),v.end());
	LL sum=0;
	for(auto it:v)sum+=it;
	LL ans=n;
	LL add=0;
	for(int i = 0;i<v.size();i++){
		ans=min(ans,add+sum-((LL)v.size()-i)*1ll*v[i]);
		sum-=v[i];
		add+=v[i];
	}
	printf("%lld\n",ans);
	return true;
}
int main(){
	int t=1;//000000;
    scanf("%d",&t);
    while(t--)solve();
}