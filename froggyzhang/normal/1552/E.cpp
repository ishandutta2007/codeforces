#include<bits/stdc++.h>
using namespace std;
#define N 10010
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
int n,m,a[N],vis[N],life[N],ins[N];
pair<int,int> ans[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n*m;++i){
		a[i]=read();
		life[i]=(n-1)/(m-1)+1;
	}
	for(int i=1;i<=n*m;++i){
		static vector<int> st;
		if(vis[a[i]])continue;
		if(ins[a[i]]){
			vis[a[i]]=1;
			auto it=--st.end();
			while(a[*it]!=a[i])--it;
			ans[a[i]]=make_pair(*it,i);
			st.erase(it);
			for(auto x:st)--life[x];
			while((it=find_if(st.begin(),st.end(),[&](int i){return !life[i];}))!=st.end()){
				ins[a[*it]]=0;
				st.erase(it);
			}
		}
		else{
			ins[a[i]]=1;
			st.push_back(i);
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}