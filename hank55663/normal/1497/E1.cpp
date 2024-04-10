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
vector<int> prime;
bool solve(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[200005];
	int ans=1;
	set<int> s;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		for(auto it:prime){
			while(a[i]%(it*it)==0){
				a[i]/=it*it;
			}
		}
		//printf("%d ",a[i]);
	//	m[a[i]]++;
	//	Max=max(Max,a[i]);
		if(s.find(a[i])!=s.end()){
			ans++;
			s.clear();
			s.insert(a[i]);
		}
		s.insert(a[i]);
	//	if(i!=0&&a[i]==a[i-1])ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int isprime[4005];
	MEM(isprime);
	for(int i=2;i<=4000;i++){
		if(!isprime[i]){
			prime.pb(i);
			for(int j = i;j<=4000;j+=i)
				isprime[j]=1;
		}
	}
	int t=1;//000000;
	scanf("%d",&t);
	while(t--)solve();
}