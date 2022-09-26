#include<bits/stdc++.h>
using namespace std;
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
int Q,cnt;
multiset<pair<int,int> > s1,s2;
int main(){
	Q=read();
	while(Q--){
		int opt=read();
		if(opt==1){
			++cnt;
			int x=read();
			s1.insert(make_pair(cnt,-x));
			s2.insert(make_pair(-x,cnt));
		}
		else if(opt==2){
			auto [id,x]=*s1.begin();
			printf("%d\n",id);
			s1.erase(s1.find(make_pair(id,x)));
			s2.erase(s2.find(make_pair(x,id)));
		}
		else{
			auto [x,id]=*s2.begin();
			printf("%d\n",id);
			s1.erase(s1.find(make_pair(id,x)));
			s2.erase(s2.find(make_pair(x,id)));
		}
	}
	return 0;
}