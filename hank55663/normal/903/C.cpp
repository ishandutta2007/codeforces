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
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[10005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	int ans=1,cnt=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}
		else{
			ans=max(ans,cnt);
			cnt=1;
		}
	//	printf("%d",cnt);
	}
	ans=max(ans,cnt);
	printf("%d\n",ans);
}