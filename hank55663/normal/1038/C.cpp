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
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	int a[100005];
	int b[100005];
	LL sum1=0,sum2=0;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.pb(x);
		sum1+=x;
		//scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.pb(x);
		sum2+=x;
		//scanf("%d",&b[i]);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	LL ans=sum1-sum2;
	int add = 1;
	for(auto it:v){
		ans+=it*add;
		add*=-1;
	}
	printf("%lld\n",ans/2);
	return 0;
}