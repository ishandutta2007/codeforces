#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define N 200200
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
ll ans;
int n,a[N];
vector<int> cnt[N];
void check(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0){
			int tmp=0;
			while(x%i==0)x/=i,++tmp;
			cnt[i].push_back(tmp);
		}
	}
	if(x>1){
		cnt[x].push_back(1);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		check(a[i]);
	}
	ans=1;
	for(int i=2;i<=200000;++i){
		if(cnt[i].empty())continue;
		sort(cnt[i].begin(),cnt[i].end());
		if(cnt[i].size()==n-1){
			for(int j=1;j<=cnt[i][0];++j){
				ans*=i;
			}
		}
		else if(cnt[i].size()==n){
			for(int j=1;j<=cnt[i][1];++j){
				ans*=i;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}