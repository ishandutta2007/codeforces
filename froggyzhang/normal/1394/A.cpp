#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
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
int n,d,m; 
vector<int> A;
priority_queue<int> q;
ll ans,now;
int main(){
	n=read(),d=read()+1,m=read();
	int cnt=0;
	for(int i=1;i<=n;++i){
		int x=read();
		if(x>m)q.push(x),++cnt;
		else A.push_back(x),now+=x;
	}
	if(cnt){
		int k=(cnt-1)/d+1;
		while(k--){
			now+=q.top();
			q.pop();
		}
	}
	sort(A.begin(),A.end());
	ans=now;
	for(auto x:A){
		q.push(x);
		now-=x;
		++cnt;
		if(cnt%d==1){
			now+=q.top();
			q.pop();
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}