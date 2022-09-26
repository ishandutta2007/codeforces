#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set> 
#include<queue>
using namespace std;
typedef long long ll;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,a[N],c[N],ans;
multiset<int> s[N];
struct TMP{
	int id;
	bool operator <(const TMP b)const{
		return s[id].size()>s[b.id].size();
	}
};
priority_queue<TMP> q;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=m;++i){
		c[i]=read();
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i){
		if(q.empty()){
			ans=1;
			s[1].insert(a[i]);
			q.push({1});
			continue;
		}
		int u=q.top().id;
		q.pop();
		if(c[a[i]]<=s[u].size()){
			++ans;
			q.push({u});
			s[ans].insert(a[i]);
			q.push({ans});
		}
		else{
			s[u].insert(a[i]);
			q.push({u});
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i){
		printf("%d ",s[i].size());
		for(auto x:s[i]){
			printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}