#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e15;
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
int T,p[5];
struct Point{
	int x,y;
}a[5];
vector<int> c;
ll calc(vector<int> t){
	sort(t.begin(),t.end());
	int n=t.size();
	int mid=t[n/2];
	ll tot=0;
	for(auto x:t){
		tot+=abs(x-mid);
	}
	return tot;
}
int main(){
	T=read();
	while(T--){
		c.clear();
		for(int i=1;i<=4;++i){
			a[i].x=read();
			a[i].y=read();
			p[i]=i;
		}
		for(int i=1;i<=4;++i){
			for(int j=i+1;j<=4;++j){
				c.push_back(abs(a[i].x-a[j].x));
				c.push_back(abs(a[i].y-a[j].y));
			}
		}
		ll ans=inf;
		do{
			for(auto z:c){
				ans=min(ans,calc(vector<int>({a[p[1]].x,a[p[2]].x+z,a[p[3]].x,a[p[4]].x+z}))+calc(vector<int>({a[p[1]].y,a[p[2]].y,a[p[3]].y+z,a[p[4]].y+z})));
			}
		}while(next_permutation(p+1,p+5));
		printf("%lld\n",ans);
	}
	return 0;
}