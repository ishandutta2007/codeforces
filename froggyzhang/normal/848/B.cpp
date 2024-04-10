#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int B=100000;
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
int n,W,H;
vector<tuple<int,int,int> > c[N];
pair<int,int> ans[N];
int main(){
	n=read(),W=read(),H=read();
	for(int i=1;i<=n;++i){
		int g=read(),p=read(),t=read();
		c[p-t+B].emplace_back(g,g==1?-p:p,i);
	}
	for(int i=1;i<=(B<<1);++i){
		sort(c[i].begin(),c[i].end());
		static vector<pair<int,int> > a;
		a.clear();
		for(auto [g,p,id]:c[i]){
			if(g==1)a.emplace_back(-p,H);
			else a.emplace_back(W,p);	
		}
		sort(a.begin(),a.end(),[&](pair<int,int> i,pair<int,int> j){return i.first==j.first?i.second<j.second:i.first>j.first;});
		for(int j=0;j<(int)a.size();++j){
			ans[get<2>(c[i][j])]=a[j];
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}