#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	LL cnt1[200005];
	LL cnt2[200005];
	vector<int> v1,v2,v3;
	for(int i = 0;i<n;i++){
		int t,a,b;
		scanf("%d %d %d",&t,&a,&b);
		if(a==1&&b==1){
			v3.pb(t);
		}
		else if(a==1){
			v1.pb(t);
		}
		else if(b==1){
			v2.pb(t);
		}
	}
	sort(v3.begin(),v3.end());
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	fill(cnt1,cnt1+200005,1e18);
	cnt1[0]=0;
	for(int i = 0;i<v1.size();i++){
		cnt1[i+1]=cnt1[i]+v1[i];
	}
	fill(cnt2,cnt2+200005,1e18);
	cnt2[0]=0;
	for(int i = 0;i<v2.size();i++){
		cnt2[i+1]=cnt2[i]+v2[i];
	}

	LL ans=cnt1[k]+cnt2[k];
	LL tmp=0;
	for(int i = 0;i<v3.size()&&i<k;i++){
		tmp+=v3[i];
		ans=min(ans,tmp+cnt1[k-i-1]+cnt2[k-i-1]);
	}
	if(ans>1e18)ans=-1;
	printf("%lld\n",ans);
	return 0;
}