#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200020
inline int read(){
    int x=0,f=1;
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
int n,p[N],c[N],vis[N],T,ans;
int solve(vector<int> &a){
	vector<int> d;
	int x=a.size();
	for(int i=1;i*i<=x;++i){
		if(x%i==0){
			d.push_back(i);
			if(i*i<x)d.push_back(x/i);
		}
	}
	sort(d.begin(),d.end());
	for(int p=0;p<d.size();++p){
		int k=d[p];
		for(int i=0;i<k;++i){
			bool ok=true;
			for (int j=i;j<x;j+=k){
				if(a[i]^a[j]){
					ok=false;break;
				}
			}
			if(ok)return k;
		}
	}
	return x;
}
void solve(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i]=read(),vis[i]=0;
	}
	for(int i=1;i<=n;++i){
		c[i]=read();
	}
	ans=n;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vector<int> tmp;
			tmp.push_back(c[i]),vis[i]=1;
			int j=p[i];
			while(j^i){
				tmp.push_back(c[j]);
				vis[j]=1;
				j=p[j];
			}	
			ans=min(ans,solve(tmp));
		}
	}
	cout<<ans<<endl;
}
int main(){
	T=read();
	while(T--){
		solve();
	}
	return 0;
}