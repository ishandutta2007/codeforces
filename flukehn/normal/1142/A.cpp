#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
typedef double ld;
typedef long long L;
typedef vector<int> VI;
typedef pair<int,int> pa;
const int oo=0x3f3f3f3f;
L mn=LONG_LONG_MAX,mx=-oo,n,k,p;
L cal(L x){
	L q=__gcd(x,p);
	return p/q;
}
void gao(L x){
	while(x<=0)x+=k;
	rep(i,0,n){
		if(x){
			L t=cal(x);
			mn=min(mn,t);
			mx=max(mx,t);
		}
		x=x+k;
	}
}
int main(){
	L a,b;
	cin>>n>>k>>a>>b;
	p=n*k;
	gao(a-b);
	gao(a+b);
	gao(k-a-b);
	gao(b-a);
	cout<<mn<<" "<<mx<<endl;
}