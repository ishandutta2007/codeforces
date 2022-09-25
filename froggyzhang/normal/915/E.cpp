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
int n,Q,ans;
struct Data{
	int l,r,w;
	Data(int _l=0,int _r=0,int _w=0){l=_l,r=_r,w=_w;}
	friend bool operator < (const Data &a,const Data &b){
		return a.l<b.l;
	}	
};
set<Data> s;
inline void Del(set<Data>::iterator it){
	ans-=(it->r-it->l+1)*it->w;
	s.erase(it);	
}
inline void Ins(Data t){
	ans+=(t.r-t.l+1)*t.w;
	s.insert(t);	
}
void Cover(int l,int r,int w){
	auto it=--s.upper_bound(Data(l,n,0));
	Data pl=*it,pr=*it;
	Del(it);
	while(it=s.lower_bound(Data(l,n,0)),it!=s.end()&&it->l<=r)pr=*it,Del(it);	
	Ins(Data(l,r,w));
	if(pl.l^l)Ins(Data(pl.l,l-1,pl.w));
	if(pr.r^r)Ins(Data(r+1,pr.r,pr.w));
}
int main(){
	n=read(),Q=read();
	s.insert(Data(1,n,1));
	ans=n;
	while(Q--){
		int l=read(),r=read(),opt=read();
		Cover(l,r,opt-1);	
		printf("%lld\n",ans);
	}
	return 0;
}