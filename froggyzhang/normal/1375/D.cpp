#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<vector>
using namespace std;
#define N 1010
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
int T,n,a[N];
inline bool check(){
	for(int i=1;i<=n;++i){
		if(a[i]^(i-1))return false;
	}
	return true;
}
inline int get_mex(){
	static int vis[N];
	for(int i=0;i<=n;++i){
		vis[i]=0;
	}
	for(int i=1;i<=n;++i){
		vis[a[i]]=1;
	}
	for(int i=0;;++i){
		if(!vis[i])return i;
	}
}
void Solve(){
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	vector<int> ans;
	while(!check()){
		int t=get_mex();
		if(t==n){
			for(int i=1;i<=n;++i){
				if(a[i]^(i-1)){
					ans.push_back(i);
					a[i]=n;
					break;
				}
			}
		}
		else{
			a[t+1]=t;
			ans.push_back(t+1); 
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}