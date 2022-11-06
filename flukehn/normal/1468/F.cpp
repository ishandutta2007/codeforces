#include<bits/stdc++.h>
using namespace std;
struct P{
	int x,y;
	P(int u=0,int v=0){
		if(u||v){
			int g=abs(__gcd(u,v));
			u/=g,v/=g;
		}
		x=u,y=v;
	}
	P operator-()const{
		return (P){-x,-y};
	}
	bool operator<(const P&t)const{
		return x==t.x?y<t.y:x<t.x;
	}
};
long long work(){
	int n;
	cin>>n;
	map<P,int> f;
	vector<P> p(n);
	for(int i=0;i<n;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		p[i]=P(c-a,d-b);
		f[p[i]]+=1;
	}
	long long ans=0;
	for(int i=0;i<n;++i)ans+=f[-p[i]];
	return ans/2;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cout<<work()<<"\n";
	}
}