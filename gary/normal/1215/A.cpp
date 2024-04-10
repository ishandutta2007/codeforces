//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int a1,a2,k1,k2;
	cin>>a1>>a2>>k1>>k2;
	vector<int> v;
	int n;
	cin>>n;
	rb(i,1,a1) v.PB(k1);
	rb(i,1,a2) v.PB(k2);
	sort(ALL(v));
	int res1=0;
	int OK=a1*(k1-1)+a2*(k2-1);
	if(OK>=n) res1=0;
	else{
		res1=n-OK;
	}
	int res2=0;
	rb(i,0,a1+a2-1){
		n-=v[i];
		res2++;
		if(n<0){
			res2--;
			break;
		}
	}
	cout<<res1<<" "<<res2;
	return 0;
}