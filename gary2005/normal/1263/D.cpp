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
int fa[200000+10],app[30],n;
string S;
vector<int> s[30];
int find_(int x){
	return (fa[x]==x)? x:fa[x]=find_(fa[x]);
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n) 
		{
			rep(j,30) app[j]=0;
			cin>>S;
			fa[i]=i;
			rep(j,S.length()){
				if(app[S[j]-'a']) continue;
				app[S[j]-'a']=1;
				s[S[j]-'a'].PB(i);
			}
		}
	rep(i,26){
		int las=-1;
		for(vector<int> :: IT ite=s[i].begin();ite!=s[i].end();ite++){
			if(las!=-1){
				fa[find_(las)]=find_(*ite);
			}
			las=*ite;
		}
	}
	int res=0;
	rb(i,1,n) if(find_(i)==i) res++;cout<<res<<endl;
	return 0;
}