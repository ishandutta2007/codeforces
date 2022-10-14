/*
AuThOr GaRyMr
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,double> mp;
typedef pair<mp,mp> superpair;
stack<pair<int,double> > s;
int main(){
//	fastio;
	int n;
	scanf("%d",&n);
	rb(i,1,n){
		int a;
		scanf("%d",&a);
		mp now=II(1,double(a));
		while(!s.empty()&&s.top().SEC>now.SEC){
			now.SEC*=(double)now.FIR;
			now.FIR+=s.top().FIR;
			now.SEC+=(double)s.top().FIR*(double)(s.top().SEC);
			now.SEC/=double(now.FIR);
			s.pop();
		}s.push(now); 
	}
	stack<mp> s2;
	while(!s.empty())
	s2.push(s.top()),s.pop();
	s=s2;
	while(!s.empty()){
		mp now=s.top();
		s.pop();
		rb(i,1,now.FIR){
			printf("%.10f\n",now.SEC);
		}
	}
	return 0;
}