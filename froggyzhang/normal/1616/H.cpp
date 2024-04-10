#include<bits/stdc++.h>
using namespace std;
#define N 150050
const int mod=998244353;
typedef long long ll;
int n,X,pw2[N];
class Trie{
	int rt,cnt;
	struct node{
		int ch[2],siz;
	}t[N*30];
	void _ins(int &u,int x,int d){
		if(!u)u=++cnt;
		++t[u].siz;
		if(d<0)return;
		int c=x>>d&1;
		_ins(t[u].ch[c],x,d-1);
	}
	int Query(int u,int v,int x,int d){
		if(!u||!v||d<0){return pw2[t[u].siz+(u==v?0:t[v].siz)];}
		if(x>>d&1){
			return u==v?Query(t[u].ch[0],t[u].ch[1],x,d-1)
					:1LL*Query(t[u].ch[0],t[v].ch[1],x,d-1)*Query(t[u].ch[1],t[v].ch[0],x,d-1)%mod;
		}
		else{
			return ((u==v?0LL:(1LL*(pw2[t[t[u].ch[0]].siz]-1)*(pw2[t[t[u].ch[1]].siz]-1)
					+1LL*(pw2[t[t[v].ch[0]].siz]-1)*(pw2[t[t[v].ch[1]].siz]-1)))%mod+
					Query(t[u].ch[0],t[v].ch[0],x,d-1)+Query(t[u].ch[1],t[v].ch[1],x,d-1)-1)%mod;
		}
	}
public:
	void Insert(int x){
		_ins(rt,x,30);
	}
	int get_ans(int X){
		return Query(rt,rt,X,30);
	}
}T;
void init(int n){
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>X;
	init(n);
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		T.Insert(x);
	}
	cout<<(T.get_ans(X)+mod-1)%mod<<'\n';
	return 0;
}