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

int main(){
	int n,a=0,b=0,x;
	cin>>n;
	rep(i,1,n){
		scanf("%d",&x);
		if(x==1)++a;
		else ++b;
	}
	if(b)printf("2 "),--b;
	if(a)printf("1 "),--a;
	rep(i,1,b)printf("2 ");
	rep(i,1,a)printf("1 ");
}