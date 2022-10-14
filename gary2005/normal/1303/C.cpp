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
int each[26],vis[26];
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		map<int,int> is;
		string s;
		cin>>s;
		rep(i,26)
			each[i]=vis[i]=0;
		each[s[0]-'a']=1;
		is[1]=s[0] -'a'+1;
		int las=-1;
		bool ok=1;
//		cout<<s.elngth()
		rep(i,s.length()){
			int now=s[i]-'a';
			if(las==-1){
				vis[now]=1;
			}
			else{
				if(vis[now])
				{
					if(abs(each[las]-each[now])<=1){
						
					}
					else{
						ok=0;
					}
				}
				else{
					if(is[each[las]-1]==0){
						is[each[las]-1]=now+1;
						each[now]=each[las]-1;
						vis[now]=1;
					}
					else
					if(is[each[las]+1]==0){
						is[each[las]+1]=now+1;
						each[now]=each[las]+1;
						vis[now]=1;
					}
					else {
						ok=0;
					}
				}
			}
			las=now;
		}
		if(!ok){
			cout<<"NO\n";
		}
		else{
			int now=INF-50;
			rep(i,26){
				if(vis[i]){
					
				}
				else{
					is[now++]=i+1;
				}
			}
			cout<<"YES\n";
			for(map<int,int> :: IT ite=is.begin();ite!=is.end();ite++){
				cout<<char(ite->SEC+'a'-1);
			}
			cout<<endl;
		}
	} 
	return 0;
}