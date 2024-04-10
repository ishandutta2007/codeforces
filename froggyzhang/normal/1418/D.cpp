#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
#define N 100010
const int inf=0x3f3f3f3f;
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
int n,Q,p[N];
set<int> tr;
multiset<int> dis;
int calc(){
	if((int)tr.size()<=4)return 0;
	return (*-- --tr.end())-(*++tr.begin())-(*--dis.end());
}
void Change(int opt,int x){
	int suf=*tr.upper_bound(x);
	int pre=*--tr.lower_bound(x);
	if(opt){
		tr.insert(x);
		if(pre>-inf&&suf<inf)dis.erase(dis.find(suf-pre));
		if(pre>-inf)dis.insert(x-pre);
		if(suf<inf)dis.insert(suf-x);
	}
	else{
		tr.erase(x);
		if(pre>-inf&&suf<inf)dis.insert(suf-pre);
		if(pre>-inf)dis.erase(dis.find(x-pre));
		if(suf<inf)dis.erase(dis.find(suf-x));
	}
}
int main(){
	n=read(),Q=read();
	tr.insert(inf),tr.insert(-inf);
	for(int i=1;i<=n;++i){
		p[i]=read();
		tr.insert(p[i]);
	}
	sort(p+1,p+n+1);
	for(int i=2;i<=n;++i){
		dis.insert(p[i]-p[i-1]);
	}
	printf("%d\n",calc());
	while(Q--){
		int opt=read(),x=read();
		Change(opt,x);
		printf("%d\n",calc());
	}
	return 0;
}