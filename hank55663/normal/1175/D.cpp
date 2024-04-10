#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[300005];
	for(int i = 0;i<n;i++)
		scanf("%d",&a[i]);
	vector<LL> v;
	LL temp=0;
	for(int i=n-1;i>0;i--){
		temp+=a[i];
		v.pb(temp);
	}
	temp+=a[0];
	LL ans=temp;
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i = 0;i<k-1;i++){
		ans+=v[i];
	}
	printf("%lld\n",ans);
}