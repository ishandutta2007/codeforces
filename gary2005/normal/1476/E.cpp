/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,m,k;
string p[100002],s[100000+23];
int mt[100000+23];
map<string,int> app; 
vector<int> g[100000+200];

void go(string ss,int mtt){
	vector<int> can;
	rep(mask,1<<k){
		string ptt="";
		rep(j,k){
			if((mask>>j)&1) ptt+=ss[j];
			else ptt+='_';
		}
		if(app.find(ptt)!=app.end()){
			can.PB(app[ptt]);
		}
	}
	bool ok=false;
	for(auto it:can){
		if(it!=mtt) g[mtt].PB(it);
		else ok=true;
	}
	if(!ok){
		cout<<"NO\n";
		exit(0);
	}
}
int tp[100000+233];
int ind[100000+20];
void topo(){
	int cnt=0;
	rb(i,1,n) for(auto it:g[i]) ind[it]++;
	queue<int> q;
	rb(i,1,n){
		if(!ind[i]) q.push(i);
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		tp[++cnt]=now;
		for(auto it:g[now]){
			ind[it]--;
			if(ind[it]==0) q.push(it);
		}
	}
	if(cnt!=n){
		cout<<"NO\n";
		exit(0);
	}
}
int main(){
	fastio;
	cin>>n>>m>>k;
	rb(i,1,n) cin>>p[i],app[p[i]]=i;
	rb(i,1,m) cin>>s[i]>>mt[i],go(s[i],mt[i]);
	topo();
	cout<<"YES\n";
	rb(i,1,n){
		cout<<tp[i]<<" ";
	}
	cout<<endl;
	return 0;
}