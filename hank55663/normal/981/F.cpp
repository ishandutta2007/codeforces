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
#define last Last
using namespace std;
typedef long long LL;
int main(){
	int n,L;
	scanf("%d %d",&n,&L);
	int a[200005];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.pb(x);
		v.pb(x+L);
		v.pb(x-L);
	}
	sort(v.begin(),v.end());
	int Max=L,Min=-1;
	while(Max>Min+1){
		int mid=(Max+Min)/2;
		int l,r;
		l=lower_bound(v.begin(),v.end(),a[0]-mid)-v.begin()-n;
		r=upper_bound(v.begin(),v.end(),a[0]+mid)-v.begin()-1-n;
	//	if(mid==1)
		//printf("%d %d\n",l,r);
		for(int i=1;i<n;i++){
			int templ=lower_bound(v.begin(),v.end(),a[i]-mid)-v.begin()-n-i;
			int tempr=upper_bound(v.begin(),v.end(),a[i]+mid)-v.begin()-n-1-i;
			l=max(templ,l);
			r=min(tempr,r);
		//	if(mid==1)
		//	printf("%d %d\n",templ,tempr);
		}
		if(l<=r)
		Max=mid;
		else
		Min = mid;
	}
	printf("%d\n",Max);
}