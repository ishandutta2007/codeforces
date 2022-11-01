#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 500050
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
int n,m,T;
int p[N];
vector<int> vec[N];
ll a[N];
bool cmp(int i,int j){
	return vec[i]<vec[j];
}
ll _gcd(ll a,ll b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();p[i]=i;
			vec[i].clear();
		}
		for(int i=1;i<=m;i++){
			int u=read(),v=read();
			vec[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			sort(vec[i].begin(),vec[i].end());
		}
		sort(p+1,p+n+1,cmp);
		sort(vec+1,vec+n+1);
		ll tmp=0,ans=0;
		for(int i=1;i<=n;i++){
			if(!vec[i].size()){
				continue; 
			}
			tmp+=a[p[i]];
			if(i==n||vec[i]!=vec[i+1]){
				if(!ans)ans=tmp;
				else ans=_gcd(ans,tmp);
				tmp=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}