#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
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
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define N 300005
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	set<int> s;
	int cnt[100005];
	MEM(cnt);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		s.insert(a);
		if(*s.rbegin()!=a){
			auto it=s.rbegin();
			it++;
			if(*it==a){
				cnt[*s.rbegin()]++;
			}
		} 
		else{
			cnt[a]--;
		}
	} 
	int ans=1,Ma=-1;
	for(int i=1;i<=n;i++){
		if(cnt[i]>Ma)
		{
			//printf("%d",i);
			Ma=cnt[i];
			ans=i;
		}
	}
	printf("%d\n",ans);
}