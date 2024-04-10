#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
#define N 200200
typedef long long ll;
inline ll read(){
    ll x=0,f=1;
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
int n,m,pos[N];
ll L,R;
vector<int> fac[N];
set<pair<int,int> > s;
int main(){
	n=read(),m=read(),L=read(),R=read();
	for(int i=1;i<=max(n,m);++i){
		for(int j=i;j<=max(n,m);j+=i){
			fac[j].push_back(i);
		}
	}
	ll l=m+1,r=m;
	for(int x1=1;x1<=n;++x1){
		ll nl=(L-1)/x1+1;
		ll nr=R/x1;
		if(nl>nr){
			puts("-1");
			continue;
		}
		while(nl<l){
			--l;
			for(auto d:fac[l]){
				s.insert(make_pair(d,l));
			}
		}
		while(nr<r){
			for(auto d:fac[r]){
				s.erase(make_pair(d,r));
			}
		    --r;
		}
		bool ok=false;
		for(auto a:fac[x1]){
			auto it=s.upper_bound(make_pair(a,2333333));
			if(it==s.end())break;
			int b=it->first;
			if(1LL*x1/a*b<=n){
				int y1=it->second;
				printf("%d %d %d %d\n",x1,y1,x1/a*b,y1/b*a);
				ok=true;
				break;
			}
		}
		if(!ok)printf("-1\n");
	}
	return 0;
}