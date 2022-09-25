#include<bits/stdc++.h>
using namespace std;
#define N 200020
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
int T,n,vis[N],a[N],c[N];
vector<int> pos[N];
mt19937 rnd(time(0));
bool check(vector<int> &A){
	if(A.empty())return true;
	if(A.size()==1){
		for(int i=1;i<=n;++i){
			if(!~c[i]){
				if(A[0]==i)return false;
			}	
		}
	}
	vector<int> t;
	for(int i=1;i<=n;++i){
		if(!~c[i]){
			t.push_back(i);		
		}
	}
	while(true){
		shuffle(A.begin(),A.end(),rnd);
		auto B=A;
		auto C=t;
		bool ok=true;
		while(!B.empty()){
			if(B.back()==C.back()){
				ok=false;
				break;
			}
			c[C.back()]=B.back();
			B.pop_back(),C.pop_back();
		}	
		if(ok)break;
	}
	return true;
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i)vis[i]=0,pos[i].clear();
	for(int i=1;i<=n;++i){
		int x=read();
		++vis[x];
		a[i]=x;
		pos[x].push_back(i);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=vis[i]>=1;
	}
	printf("%d\n",ans);
	if(ans==n-1){
		for(int i=1;i<=n;++i)c[i]=-1;
		vector<int> tmp;
		for(int i=1;i<=n;++i){
			if(!pos[i].empty())c[pos[i].back()]=i;
			else tmp.push_back(i);	
		}
		if(!check(tmp)){
			tmp.clear();
			for(int i=1;i<=n;++i)c[i]=-1;
			for(int i=1;i<=n;++i){
				if(!pos[i].empty())c[pos[i][0]]=i;
				else tmp.push_back(i);	
			}
			check(tmp);
		}
	}
	else{
		for(int i=1;i<=n;++i)c[i]=-1;
		vector<int> tmp;
		for(int i=1;i<=n;++i){
			if(!pos[i].empty())c[pos[i].back()]=i;
			else tmp.push_back(i);	
		}
		check(tmp);
	}
	for(int i=1;i<=n;++i){
		printf("%d ",c[i]);
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}