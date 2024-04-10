#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
pll operator-(const pll &p1,const pll &p2){
	return {p1.x-p2.x,p1.y-p2.y};
}
int main(){
	int n;
	scanf("%d",&n);
	map<LL,LL> m;
	for(int i =0;i<n;i++){
		LL x=i,y=0;
		scanf("%lld %lld",&x,&y);
		if(m.find(x)!=m.end())
		m[x]=max(m[x],y);
		else
		{
			m[x]=y;	
		}
	}
	vector<pll> v;
	for(auto it:m)
	v.pb(it);
	int last=0;
	int ans=0;
	vector<pll> stk;
	stk.pb(v[0]);
	if(v.size()>1)
	stk.pb(v[1]);
	for(int i =2;i<v.size();i++){
		//nowv[i+1]
		while(stk.size()>1){
			int len=stk.size();
			pll p1 = stk[len-1];
			pll p2 = stk[len-2];
			pll p3 = v[i];
			//p2 = p2 - p1;
			//p3 = p3 - p1;
			LL A = p1.y-p1.x*p1.x;
			LL B = p1.x;
			LL C = 1;
			LL D = p2.y-p2.x*p2.x;
			LL E = p2.x;
			LL F = 1;
			long double b=(long double)(A*F-C*D)/(B*F-C*E);
			long double c=(long double)(B*D-A*E)/(B*F-C*E);
		//	double b=(double)(p2.y-p2.x*p2.x)/(p2.x);
			// y = x^2 + bx
			double myy=p3.x*p3.x + b*p3.x + c ;
			if(myy>p3.y+1e-6){
				break;
			}
			stk.pop_back();
		}
		stk.pb(v[i]);;
	}
//	if(ans==0)
//		assert(v.size()==1);
	printf("%d\n",stk.size()-1);
}
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc