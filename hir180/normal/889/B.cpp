#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
string x[100005];
string hoge[26];
int nxt[26],go[26];
bool in[26],ex[26];
int main(){
	cin>>n;
	rep(i,n){
		cin>>x[i];
		if(x[i].size() > 26){
			puts("NO"); return 0;
		}
		bool used[26]={};
		rep(j,x[i].size()){
			if(used[x[i][j]-'a'] == 1){
				puts("NO"); return 0;
			}
			used[x[i][j]-'a'] = 1;
		}
	}
	rep(i,n){ 
		for(int j=0;j<x[i].size();j++){
			ex[x[i][j]-'a']=1;
			if(j) nxt[x[i][j-1]-'a'] |= 1<<(x[i][j]-'a');
		}
	}
	memset(go,-1,sizeof(go)); int C = 0;
	rep(i,26){
		C += ex[i];
		if(__builtin_popcount(nxt[i]) >= 2){
			puts("NO"); return 0;
		}
		else if(__builtin_popcount(nxt[i]) == 1){
			for(int j=0;j<26;j++){
				if( (1<<j) == nxt[i] ){
					assert(i!=j);
					go[i] = j;
					in[j] = 1; //cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}
	}
//	cout<<go[5]<<endl;
	vector<string>vs; //cout<<nxt[5]<<endl;
	rep(i,26){
		if(in[i] || !ex[i]) continue;
		string ad=""; ad.pb('a'+i);
		int r = 0,c = i;
		while(1){
			int vt = go[c]; r++;
			if(vt == -1) break;
			if(r > 100) { puts("NO"); return 0;}
			ad.pb('a'+vt); c = vt; //cout<<vt<<endl;
		}
		vs.pb(ad); //cout<<ad<<endl;
	}
	if(vs.empty()){
		puts("NO"); return 0;
	}
	sort(vs.begin(),vs.end());
	for(int i=vs.size()-1;i>=0;i--){
	//	if(ex[vs[i][0]] == 0) continue;
		string ret = "";
		for(int j=0;j<=i;j++) ret += vs[j];
		if(ret.size() != C){
			puts("NO"); return 0;
		}
		cout<<ret<<endl; return 0;
	}
}