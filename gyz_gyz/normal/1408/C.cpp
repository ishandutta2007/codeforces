#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
const int mo=1e9+7;
const ll inf=1e18;
double a[N];
void sol(){
	int n,s=1;double t=0,l=0,r,vl=1,vr=1;
	scanf("%d%lf",&n,&r);
	rep(i,1,n)scanf("%lf",&a[i]);
	while(s<=n){
		double t1=(a[s]-l)/vl,t2=(r-a[n])/vr;
		if(t1<t2){
			t+=t1;l+=t1*vl;r-=t1*vr;vl+=1;++s;
		}else{
			t+=t2;l+=t2*vl;r-=t2*vr;vr+=1;--n;
		}
	}
	t+=(r-l)/(vl+vr);
	printf("%.15lf\n",t);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}