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
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int fa[400000+1];
int find_(int a){
	if(fa[a]==a) return a;
	return fa[a]=find_(fa[a]);
}
int main(){
	fastio;
	int n,m;
	int q;
	cin>>n>>m>>q;
	rb(i,1,n+m)
		fa[i]=i;
	rb(i,1,q){
		int a,b;
		cin>>a>>b;
		fa[find_(a)]=find_(n+b);
	}
	int res=0;
	rb(i,1,n+m){
		if(find_(i)==i){
			res++;
		}
	}cout<<res-1;
	return 0;
}