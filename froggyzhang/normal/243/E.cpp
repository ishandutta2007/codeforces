#include<bits/stdc++.h>
using namespace std;
#define N 1010
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
int n,m;
class PQ_Tree{
private:
	int n;
public:
	struct node{
		vector<int> son;
		int type,op;
	}t[N<<2];	
	bitset<N> vis;
	int tot,rt;
	bool OK;
	void init(int _n){
		tot=n=_n;
		rt=++tot;
		for(int i=1;i<=n;++i)t[rt].son.push_back(i);
	}
	void dfs1(int u){
		if(u<=n)return (void)(t[u].op=vis[u]?2:1);
		t[u].op=0;
		for(auto v:t[u].son)dfs1(v),t[u].op|=t[v].op;	
	}
	void dfs2(int u,int lim){
		if(!OK||t[u].op^3)return;
		vector<int> a[4];
		for(auto v:t[u].son)a[t[v].op].push_back(v);
		if((lim>0)+a[3].size()>=3)OK=false;
		if(!lim&&a[2].size()+a[3].size()<=1){
			if(!a[2].empty())dfs2(a[2][0],0);
			if(!a[3].empty())dfs2(a[3][0],0);
			return;	
		}
		if(t[u].type){
			int now=0;
			vector<int> S;
			if(t[t[u].son[0]].op==2||t[t[u].son.back()].op==1)reverse(t[u].son.begin(),t[u].son.end());
			for(auto v:t[u].son){
				if(t[v].op==1){
					now+=now==1;
					S.push_back(v);
				}
				else if(t[v].op==2){
					if(now==2)OK=false;
					now+=!now;
					S.push_back(v);
				}
				else{
					if(now==2)OK=false;
					++now;
					dfs2(v,3-now);
					S.insert(S.end(),t[v].son.begin(),t[v].son.end());
				}	
			}
			if(lim&&now==2)OK=false;
			if(lim==1)reverse(S.begin(),S.end());
			t[u].son=S;
		}
		else{
			int z=-1;
			if(a[2].size()==1)z=a[2][0];
			else if(a[2].size()>1)z=++tot,t[z].son=a[2],t[z].type=0;
			vector<int> S;
			if(!a[3].empty()){
				dfs2(a[3][0],2);
				S.insert(S.end(),t[a[3][0]].son.begin(),t[a[3][0]].son.end());
			}
			if(~z)S.push_back(z);
			if(a[3].size()>1){
				dfs2(a[3][1],1);
				S.insert(S.end(),t[a[3][1]].son.begin(),t[a[3][1]].son.end());
			}
			if(a[1].empty()){
				if(lim==1)reverse(S.begin(),S.end());
				t[u].type=1,t[u].son=S;	
			}
			else{
				if(lim){
					t[u].son.clear();
					t[u].type=1;
					z=a[1][0];
					if(a[1].size()>1)z=++tot,t[z].type=0,t[z].son=a[1];
					t[u].son.push_back(z);
					t[u].son.insert(t[u].son.end(),S.begin(),S.end());
					if(lim==1)reverse(t[u].son.begin(),t[u].son.end());
				}
				else{
					z=S[0];
					if(S.size()>1)z=++tot,t[z].type=1,t[z].son=S;
					t[u].son=a[1],t[u].son.push_back(z);
				}
			}
		}
	}
	bool Insert(const bitset<N> &B){
		vis=B;
		dfs1(rt);OK=true;dfs2(rt,0);
		return OK;	
	}
	void dfs3(int u,vector<int> &p){
		if(u<=n)return p.push_back(u);
		for(auto v:t[u].son)dfs3(v,p);
	}
}T;
string s[N];
vector<int> ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	T.init(n);
	for(int i=1;i<=n;++i){
		cin>>s[i];
		static bitset<N> B;
		for(int j=1;j<=n;++j){
			B[j]=s[i][j-1]-'0';
		}
		if(!T.Insert(B)){
			return !printf("NO\n");
		}
	}
	printf("YES\n");
	T.dfs3(T.rt,ans);
	for(int i=1;i<=n;++i){
		for(int j=0;j<n;++j){
			putchar(s[i][ans[j]-1]);		
		}
		putchar('\n');
	}
	return 0;
}