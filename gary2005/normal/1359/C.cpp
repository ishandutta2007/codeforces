/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
//	fastio;
	int T;
	cin>>T;
	LL l,l1,r,r1;
	LL h,c,t;
	int cc=0;
	while(T--){
		cin>>h>>c>>t;
//		cout<<++cc<<endl;
		l=0,r=10000000000ll;
		while(l<r-1){
			LL mid=(l+r)>>1;
			if((double)(c*mid+h*(mid+1))/(double)(mid*2+1)>=(double)(t)){
				
				l=mid;
			}
			else{
				r=mid;
			}
		}
		if(abs((double)(c*l+h*(l+1))/(double)(l+l+1)-(double)(t))>abs((double)t-(double)(c*r+h*(r+1))/(double)(r+r+1)))
		l=r;
		if(abs((double)(c*l+h*(l+1))/(double)(l+l+1)-(double)(t))>=(double)(abs((double)t-double(h+c)/2.0))){
			cout<<2<<endl;
		}
		else{
//			printf("%.10f\n",(double)(c*l+h*(l+1))/(double)(l+l+1));
//			printf("%.10f\n",(abs((double)t-double(h+c)/2.0)));
			cout<<l*2+1<<endl;
		}
	}
	return 0;
}
/*
7 1 6
*/