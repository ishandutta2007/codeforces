#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
#define py cout<<"YES\n"
#define pn cout<<"NO\n";
vector<int>son[N];
void dfs(int now,int fat){
	for(int T,i=0;i<son[now].size();++i)
		if((T=son[now][i])!=fat)dfs(T,now);
}
int T,n,k,i,l,r,mid,j,x,y,m,a[N],b[N];
int check(int x){
	int ee=0;
	for(i=1;i<=n;++i){
		if(a[i]>=ee&&b[i]>=x-ee-1){
			++ee;
			if(ee==x)return 1;
		}
	}
	return 0;
}
int main(){cin.tie(0);
	T=1;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>b[i]>>a[i];
		}
		l=1;r=n;
		while(l<r){
			mid=r-(r-l>>1);
			if(check(mid))l=mid;
			else r=mid-1;
		}
		cout<<l<<"\n";
	}
}