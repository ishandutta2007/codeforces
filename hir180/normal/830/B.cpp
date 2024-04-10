#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[100005];
priority_queue<int,vector<int>,greater<int> >que;
vector<int>pos[100005];
struct BIT
{
	int bit[(1<<20)+5];
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		for(int s=i;s<=(1<<20);s+=f(s)) bit[s]+=x;
	}
	int sum(int i)
	{
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=bit[s];
		return res;
	}
}bit;
int main(){
	cin>>n;
	rep(i,n){
		cin>>a[i];
		pos[a[i]].pb(i);
	}
	int cur = 0; ll ans = 0;
	for(int i=0;i<=100000;i++){
		int zan = pos[i].size();
		int x = POSL(pos[i],cur);
		if(x == pos[i].size()) x = 0;
		for(;zan;x=(x+1)%pos[i].size()){
			int f = x;
			//cur -> pos[i][f];
			if(cur <= pos[i][f]){
				ans += pos[i][f]-cur-(bit.sum(pos[i][f])-bit.sum(cur));
			}
			else{
				ans += n-cur-(bit.sum(n)-bit.sum(cur));
				ans += pos[i][f]-bit.sum(pos[i][f]);
			}
			//cout<<ans<<" "<<pos[i][f]<<endl;
			cur = pos[i][f]+1; bit.add(pos[i][f]+1,1);
			zan--;
		}
	}
	cout<<ans+n<<endl;
}