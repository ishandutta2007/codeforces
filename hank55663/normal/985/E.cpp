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
using namespace std;
typedef long long LL;
int main(){
	int n,k,d;
	scanf("%d %d %d",&n,&k,&d);
	int a[500005];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n);
	vector<int> ok;
	ok.pb(-1);
	for(int i=k-1;i<n;i++){
	//	printf("%d\n",i);
		auto it=upper_bound(ok.begin(),ok.end(),i-k);
		it--;
		if(a[i]-a[*it+1]<=d){
			ok.pb(i);
		}
	}
	if(ok.back()==n-1){
		printf("YES\n");
	}
	else
	printf("NO\n");
}