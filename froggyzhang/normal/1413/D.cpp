#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
#define N 100010
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
int n,p[N],ans[N<<1];
set<int> s,A;
int main(){
	n=read();
	for(int i=1;i<=n<<1;++i){
		char c=getchar();
		while(c!='+'&&c!='-')c=getchar();
		if(c=='+'){
			s.insert(i);
		}
		else{
			int x=read();
			p[x]=i;
			A.insert(i);
		}
	}
	s.insert(-1);
	for(int i=1;i<=n;++i){
		int u=p[i];
		int pos=*--s.lower_bound(u);
		if(!~pos)return !printf("NO\n");
		ans[pos]=i;
		s.erase(pos);
		if(*A.lower_bound(pos)^u)return !printf("NO\n");
		A.erase(u);
	}
	printf("YES\n");
	for(int i=1;i<=n<<1;++i){
		if(ans[i])printf("%d ",ans[i]);
	}
	return 0;
}