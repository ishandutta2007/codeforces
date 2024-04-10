#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,p[N];
ll a[N];
class BIT{
	ll b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline int Find(ll k){
		int ans=0;
		for(int i=18;i>=0;--i){
			if(ans+(1<<i)<=n&&b[ans+(1<<i)]<=k){
				ans+=1<<i;
				k-=b[ans];
			}
		}
		return ans+1;
	}
}B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		B.Add(i,i);
	}
	for(int i=n;i>=1;--i){
		p[i]=B.Find(a[i]);
		B.Add(p[i],-p[i]);
	}
	for(int i=1;i<=n;++i){
		cout<<p[i]<<' ';
	}
	return 0;
}