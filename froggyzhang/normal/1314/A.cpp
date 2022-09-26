#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
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
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
ll ans,now;
struct QAQ{
	int t,p;
}a[N];
bool cmp1(QAQ a,QAQ b){
	return a.p<b.p;
}
multiset<int> s;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].p=read();
	}
	for(int i=1;i<=n;++i){
		a[i].t=read();
	}
	sort(a+1,a+n+1,cmp1);
	a[n+1].p=2e9;
	for(int i=1;i<=n+1;++i){
		for(int j=a[i-1].p;j<=a[i].p-1;++j){
			if(s.empty())break;
			now-=(*--s.end());
			s.erase(--s.end());
			ans+=now;
		}
		now+=a[i].t;
		s.insert(a[i].t);
	}
	printf("%I64d\n",ans);
	return 0;
}