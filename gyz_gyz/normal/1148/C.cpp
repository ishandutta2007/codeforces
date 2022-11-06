#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=998244353;
int a[N],b[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		b[a[i]]=i;
	}vector<pair<int,int>>v;
	rep(i,1,n)if(a[i]!=i){
		if((b[i]-i)*2>=n){
			v.pb({i,b[i]});
		}else{
			int x=(i-1)*2>=n?1:n;
			int y=(b[i]-1)*2>=n?1:n;
			if(x==y){
				v.pb({i,x});v.pb({x,b[i]});v.pb({i,x});
			}else{
				v.pb({i,x});v.pb({b[i],y});v.pb({x,y});
				v.pb({i,x});v.pb({b[i],y});
			}
		}
		swap(a[i],a[b[i]]);b[a[b[i]]]=b[i];b[i]=i;
	}
	cout<<v.size()<<'\n';
	for(auto &i:v)printf("%d %d\n",i.fr,i.sc);
}