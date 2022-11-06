#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define fo(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
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
const int N=1e5+11,M=22,oo=~0u>>2;
int n;
struct P{
	L x,y;
	P(L x=0,L y=0):x(x),y(y){}
	P operator-(const P&t)const{
		return P(x-t.x,y-t.y);
	}
	bool operator<(const P&t)const{
		return x!=t.x?x<t.x:y<t.y;
	}
	L operator*(const P&t)const{
		return x*t.y-t.x*y;
	}
} a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	L x,y;
	rep(i,1,n){
		cin>>x>>y;
		a[i]=P(x,y-x*x);
	}
	sort(a+1,a+n+1);
	int t=0;
	rep(i,1,n){
		while(t>1&&(a[i]-b[t-1])*(b[t]-b[t-1])<=0)--t;
		b[++t]=a[i];
	}
	rep(i,1,n)if(b[i].x==b[1].x)--t;
	cout<<t<<endl;
}