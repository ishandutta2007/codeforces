#include<bits/stdc++.h>
using namespace std;
#define N 55
const int mod=1e9+7;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,ans[N<<1],dp[N<<1][2][N];
vector<int> a[N][N],t[2][2][N][N];
bool G[N][N];
bool ext_front(deque<int> &q,deque<int>::iterator it){
	while(it!=q.begin()&&q.size()<=(n<<1|1)){
		auto nxt=it-1;
		if(!G[*nxt][*it])return false;
		q.insert(q.begin(),a[*nxt][*it].begin(),a[*nxt][*it].end());
		--it;
	}
	return q.size()<=(n<<1|1);
}
bool ext_back(deque<int> &q,deque<int>::iterator it){
	while(it+1!=q.end()&&q.size()<=(n<<1|1)){
		auto nxt=it+1;
		if(!G[*it][*nxt])return false;
		q.insert(q.end(),a[*it][*nxt].begin(),a[*it][*nxt].end());
		++it;
	}
	return q.size()<=(n<<1|1);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),k=read();
		G[u][v]=true;
		while(k--){
			a[u][v].push_back(read());
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(G[i][j]&&!a[i][j].empty()&&a[i][j].back()==i){
				deque<int> q(a[i][j].begin(),a[i][j].end());
				if(ext_front(q,--q.end()))t[0][0][q.front()][j].push_back(q.size());
			}
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(G[i][j]&&!a[i][j].empty()&&a[i][j].front()==j){
				deque<int> q(a[i][j].begin(),a[i][j].end());
				if(ext_back(q,q.begin()))t[1][1][i][q.back()].push_back(q.size());
			}
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(G[i][j]&&!a[i][j].empty()){
				deque<int> q(a[i][j].begin(),a[i][j].end());
				auto p=find(q.begin(),q.end(),i);
				if(p==q.end()||p+1==q.end()||*(p+1)!=j)continue;
				if(ext_front(q,p)&&ext_back(q,p+1)){
					t[0][1][q.front()][q.back()].push_back(q.size()-1);
				}
			}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(G[i][j]&&a[i][j].empty())t[1][0][i][j].push_back(1); 
	
	for(int i=1;i<=n;++i){
		dp[0][0][i]=1;
	}
	
	#define update(x,y) x=(x+y)%mod
	for(int len=0;len<(n<<1);++len)
		for(int p=0;p<=1;++p)
			for(int i=1;i<=n;++i){
				int w=dp[len][p][i];
				if(!w)continue;
				for(int q=0;q<=1;++q){
					for(int j=1;j<=n;++j){
						for(int z:t[p][q][i][j]){
							if(len+z<=(n<<1))update(dp[len+z][q][j],w);
						}
					}
				}
			}
	
	for(int len=1;len<=(n<<1);++len){
		int ans=0;
		for(int i=1;i<=n;++i){
			update(ans,dp[len][1][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}