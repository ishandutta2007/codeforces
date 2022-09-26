#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
#define N 200010
inline int read(){
	int x=0,f=1;
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
int T,n,X,Y,cnt[N],a[N],b[N],p[N];
vector<int> pos[N];
struct COL{
	int cnt,type;
	bool operator <(const COL b)const{
		return make_pair(cnt,type)>make_pair(b.cnt,b.type);
	}
};
set<COL> s;
void Solve(){
	n=read(),X=read(),Y=read();
	for(int i=1;i<=n+1;++i){
		cnt[i]=a[i]=b[i]=0;
		pos[i].clear();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
		++cnt[b[i]];
		pos[b[i]].push_back(i);
	}
	if(X==n){
		printf("YES\n");
		for(int i=1;i<=n;++i){
			printf("%d ",b[i]);
		}
		printf("\n");
		return;
	}
	s.clear();
	for(int i=1;i<=n+1;++i){
		s.insert((COL){cnt[i],i});
	}
	for(int i=1;i<=X;++i){
		COL u=(*s.begin());
		s.erase(s.begin());
		a[pos[u.type].back()]=u.type;
		pos[u.type].pop_back();
		--u.cnt;
		s.insert(u);
	}
	vector<int> res;
	for(auto c:s){
		for(auto x:pos[c.type]){
			res.push_back(x);
		}
	}
	int now=(pos[s.begin()->type].size())%res.size();
	for(auto c:s){
		for(auto x:pos[c.type]){
			if(X==Y)break;
			if(c.type==b[res[now]])continue;
			a[res[now]]=c.type;
			now=(now+1)%res.size();
			--Y;
		}
	}
	if(X^Y){
		printf("NO\n");
		return;
	}
	int qwq=0;
	for(int i=1;i<=n;++i){
		if(!a[i])a[i]=(--s.end())->type;
		qwq+=(a[i]==b[i]);
	}
	if(qwq^X){
		printf("NO\n");
		return;
	}
	printf("YES\n");
	for(int i=1;i<=n;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}