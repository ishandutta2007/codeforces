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
#define index Index
using namespace std;
int Next[100005];
#define prev Prev
int prev[100005];
bool solve(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)Next[i]=i+1;//prev[i]=i-1;
	Next[n]=1;
	prev[1]=n;
	int a[100005];
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	set<int> s;
	for(int i = 1;i<=n;i++){
		if(__gcd(a[i],a[Next[i]])==1){
			s.insert(i);
		}
	}
	int now=1;
	vector<int> v;
	while(s.size()){
		auto x=s.lower_bound(now);
		if(x==s.end())x=s.begin();
		v.pb(Next[*x]);
		Next[*x]=Next[Next[*x]];
		now=Next[*x];
		if(s.find(v.back())!=s.end())s.erase(v.back());
		if(__gcd(a[*x],a[now])==1);
		else
		s.erase(x);
		if(s.size()==n)break;
	}
	printf("%d ",v.size());
	for(auto it:v)printf("%d ",it);
	printf("\n");
	return true;
}
int main(){
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}