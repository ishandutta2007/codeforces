#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
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
int T,n,a[N],p[233],mx,sum[N][233]; 
vector<int> vec[233];
int main(){
	T=read();
	while(T--){
		n=read();mx=0;
		int ans=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=mx;++i){
			vec[i].clear();
		}
		for(int i=1;i<=n;++i){
			vec[a[i]].push_back(i);
			for(int j=1;j<=mx;++j){
				sum[i][j]=sum[i-1][j];
			}
			++sum[i][a[i]];
		}
		for(int i=1;i<=mx;++i){
			ans=max(ans,(int)vec[i].size());
			if(vec[i].size()<2)continue;
			int l=0,r=vec[i].size()-1;
			while(l<r){
				for(int j=1;j<=mx;++j){
					ans=max(ans,2*(l+1)+sum[vec[i][r]-1][j]-sum[vec[i][l]][j]);
				}
				++l,--r;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}