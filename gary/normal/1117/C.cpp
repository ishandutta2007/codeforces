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
LL n,x1,y1,x2,y2;string s;
bool check(LL x){
	if(x<=n){
		LL X,Y;
		X=Y=0;
		rep(i,x){
			if(s[i]=='U') Y++;
			if(s[i]=='D') Y--;
			if(s[i]=='L') X--;
			if(s[i]=='R') X++;
		}
		LL tmpx=x1,tmpy=y1;
		tmpx+=X;
		tmpy+=Y;
		LL dis=abs(tmpx-(LL)(x2))+abs(tmpy-(LL)(y2));
		if(dis<=x) return 1;
		return 0;
	}
	else{
		LL tot=x/n;
		LL rest=x%n;
		LL X,Y;
		X=Y=0;
		rep(i,n){
			if(s[i]=='U') Y++;
			if(s[i]=='D') Y--;
			if(s[i]=='L') X--;
			if(s[i]=='R') X++;
		}
		X*=tot,Y*=tot;
		rep(i,rest){
			if(s[i]=='U') Y++;
			if(s[i]=='D') Y--;
			if(s[i]=='L') X--;
			if(s[i]=='R') X++;
		}
		LL tmpx=x1,tmpy=y1;
		tmpx+=X;
		tmpy+=Y;
		LL dis=abs(tmpx-(LL)(x2))+abs(tmpy-(LL)(y2));
//		cout<<dis<<endl;
		if(dis<=x) return 1;
		return 0;
	}
}
int main(){
	cin>>x1>>y1>>x2>>y2;
	cin>>n;
	
	cin>>s;
	LL l=0,r=2e14+10;
	while(l<r){
		LL mid=(l+r)>>1;
		if(check(mid)){
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
//	cout<<check(l)<<endl;
	if(l>2e14){
		puts("-1");
		return 0;
	}
	else{
		cout<<l<<endl;
	}
	return 0;	
}
/*
0 0
4 6
3
UUU
*/