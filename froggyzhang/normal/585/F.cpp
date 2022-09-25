#include<bits/stdc++.h>
using namespace std;
#define N 1010
#define M 55
const int mod=1e9+7;
typedef long long ll;
int dp[M][N*M][2][2];
class ACAM{
	int tot;
	struct node{
		int ch[10],fa,nxt;
		bool ed;
	}t[N*M];
public:
	ACAM(){tot=1;}
	void Insert(const string &s){
		int u=1;
		for(auto _c:s){
			int c=_c-'0';
			if(!t[u].ch[c])t[u].ch[c]=++tot;
			u=t[u].ch[c];
		}
		t[u].ed=1;
	}
	void build(){
		queue<int> q;
		for(int i=0;i<10;++i){
			t[0].ch[i]=1;
		}
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			t[u].ed|=t[t[u].nxt].ed;
			for(int c=0;c<10;++c){
				int v=t[u].ch[c];
				if(v){
					t[v].nxt=t[t[u].nxt].ch[c];
					q.push(v);
				}
				else{
					t[u].ch[c]=t[t[u].nxt].ch[c];
				}
			}
		}
	}
	int work(string s){
		if(s[0]==-1)return 0;
		int n=s.length();
		s=' '+s;
		memset(dp,0,sizeof(dp));
		dp[0][1][1][0]=1;
		#define update(x,y) x=(x+y)%mod
		for(int i=1;i<=n;++i){
			for(int u=1;u<=tot;++u){
			 	for(int up=0;up<2;++up){
			 		for(int ok=0;ok<2;++ok){
			 			int lim=up?s[i]-'0':9;
			 			int w=dp[i-1][u][up][ok];
					 	if(!w)continue;
					 	for(int c=0;c<=lim;++c){
					 		int v=t[u].ch[c];
					 		update(dp[i][v][up&&c==lim][ok|t[v].ed],w);
					 	}
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=tot;++i){
			update(ans,(dp[n][i][0][1]+dp[n][i][1][1])%mod);
		}
		return ans;
		return 0;
	}
}T;
string Minus(string s){
	for(int i=(int)s.length()-1;i>=0;--i){
		if(s[i]>'0'){
			--s[i];
			return s;
		}
		else{
			s[i]='9';
		}
	}
	s[0]=-1;
	return s;
}
int n,m;
string s,A,B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>A>>B;
	n=s.length(),m=A.length();
	for(int i=0;i<(int)s.length()-m/2+1;++i){
		T.Insert(s.substr(i,m/2));
	}
	T.build();
	cout<<(T.work(B)-T.work(Minus(A))+mod)%mod<<'\n';
	return 0;
}