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
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		k++;
		int a[200005];
		for(int i = 0;i<n;i++)
			scanf("%d",&a[i]);
		int Max=1e9,Min=-1;
		while(Max>Min+1){
			int mid=(Max+Min)/2;
			vector<pii> v;
			for(int i= 0;i<n;i++){
				v.pb(mp(a[i]-mid,1));
				v.pb(mp(a[i]+mid+1,-1));
			}
			sort(v.begin(),v.end());
			int NMax=0,sum=0;
			for(auto it:v){
				sum+=it.y;
				NMax=max(NMax,sum);
			}
			if(NMax>=k){
				Max=mid;
			}
			else{
				Min=mid;
			}
		}
		vector<pii> v;
		for(int i = 0;i<n;i++){
			v.pb(mp(a[i]-Max,1));
			v.pb(mp(a[i]+Max+1,-1));
		}
		sort(v.begin(),v.end());
		int sum=0;
		for(auto it:v){
			sum+=it.y;
			if(sum>=k){
				printf("%d\n",it.x);
				break;
			}
		}
	}
}