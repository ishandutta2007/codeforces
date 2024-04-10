/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int f[1000000+2][2];
string s;
int a[1000000+2];
vector<int> can[1000000+2];
int nxt[1000000+2];
int main(){
	fastio;
	int n;
	R2(n,s);
	s='#'+s;
	rb(i,1,n){
		a[i]=s[i]^48;
	}
	rb(i,1,n)
	{
		if(a[i]!=0&&a[i]!=1)
			a[i]=3;
	}
	rl(i,n,1){
		if(a[i]==3){
			f[i][0]=f[i+1][0]+1;
			f[i][1]=f[i+1][1]+1;
		}
		else{
			f[i][a[i]]=f[i+1][a[i]]+1;
		}
	}
	set<int> pos;
	set<int> :: IT ite;
	rb(i,1,n){
		f[i][0]=max(f[i][0],f[i][1]);
		can[f[i][0]].PB(i);
	}
	vector<int> rest;
	rb(i,1,n){
		int res=0;
		int las=1;
		while(1){
			while(nxt[las]&&nxt[nxt[las]]) las=nxt[las]=nxt[nxt[las]];
			if(nxt[las]) las=nxt[las];
			if(las+i-1>n) break;
			las+=i;
			res++;
		}
		for(auto it:can[i])
			nxt[it]=it+1;
		rest.PB(res);
	}
	for(auto it:rest){
		cout<<it<<" ";
	}
	return 0;
}