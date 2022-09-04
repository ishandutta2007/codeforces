#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	LL n,k;
	scanf("%lld %lld",&n,&k);
	LL l=1,r=n;
	srand(time(NULL));
	while(1){
		if(r-l+1>40){
			LL mid=(r+l)/2;
			printf("%lld %lld\n",l,mid);
			fflush(stdout);
			string s;
			cin>>s;
			if(s=="Yes"){
				l=l-k;
				r=mid+k;
			}
			else{
				l=mid+1-k;
				r=r+k;
			}
			l=max(l,1ll);
			r=min(r,n);
		}
		else{
			LL x=rand()%(r-l+1);
			printf("%lld %lld\n",x+l,x+l);
			fflush(stdout);
			string s;
			cin>>s;
			if(s=="Yes")
			return 0;
			l=l-k;
			r=r+k;
			l=max(l,1ll);
			r=min(r,n);
		}
	}
}