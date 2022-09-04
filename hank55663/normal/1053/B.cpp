#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
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
	vector<int> v;
	int odd[300005],even[300005];
	odd[0]=0;
	even[0]=1;
	v.pb(0);
	int now=0;
	LL ans=0,ans22=0;
	LL last=0;
	//srand(time(NULL));
	for(int i=1;i<=n;i++){
		LL x;
		scanf("%lld",&x);
		//x=rand()+1;
		int cnt=0;
		while(x){
			if(x&1)cnt++;
			x>>=1;
		}
		now+=cnt;
		int tot=cnt,Max=cnt;
		for(int j=i-1;j>=i-70&&j>0;j--){
			tot+=v[j];
			Max=max(Max,v[j]);
			if(tot%2==0&&Max<=tot/2)
				ans++;
		}
		v.pb(cnt);
		even[i]=even[i-1];
		odd[i]=odd[i-1];
		if(now%2==0)
		even[i]++;
		else
		odd[i]++;
		if(i>71){
			if(now%2==0)
			ans+=even[i-72];
			else
			ans+=odd[i-72];
		}
	}
	printf("%lld\n",ans);
}