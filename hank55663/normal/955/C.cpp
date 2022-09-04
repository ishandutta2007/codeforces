#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
vector<LL> v;
LL sqrr(LL a){
	LL Max=1e9+1,Min=0;
	while(Max>Min+1){
		LL mid=(Max+Min)/2;
		if(mid*mid>a)
		Max=mid;
		else
		Min=mid;
	}
	return Min;
}
LL cal(LL a){
	LL ret=upper_bound(v.begin(),v.end(),a)-v.begin();
	ret+=sqrr(a);
	return ret;
}
int main(){
	vector<LL> s;
	for(int i=3;i<63;i++){
		for(int j=1;;j++){
			LL num=1;
			for(int k=0;k<i;k++){
				LL last=num;
				num*=j;
				if(num>1e18||num/j!=last){
					num=1e18+1;
					break;
				}
			}
			if(num!=1e18+1){
				LL x=sqrr(num);
				if(x*x!=num){
					s.pb(num);
				}
			}
			else{
				break;
			}
		}
	//	printf("%d\n",i);
	}
	sort(s.begin(),s.end());
	
	v.pb(s[0]);
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1])
		v.pb(s[i]);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		LL l,r;
		scanf("%lld %lld",&l,&r);
		printf("%lld\n",cal(r)-cal(l-1));
	}
}
/*
BC
ACC
AABC
CC
ABC
AACC*/