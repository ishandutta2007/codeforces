#pragma GCC optimize(2)
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
int T,n,ANS,ans,i,j,k,tot,l,r,mid,val[N],x,y,m,a[N];
int find(int x){
	l=1;r=n;
	while(l<r){
		mid=r-(r-l>>1);
		if(a[mid]<=x)l=mid;
		else r=mid-1;
	}
	return a[l];
}
int main(){
	T=1;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>a[i];
		}
		a[n+1]=-1;ANS=0;
		for(i=1;i<=n;i=j){
			if(a[i]!=a[i-1]){
				for(j=i;;++j)if(a[j]!=a[i])break;
				ans=j-i;
				x=a[n]-a[i];
				while(x>0)x=find(x/2+a[i])-a[i],++ans;
				ANS=max(ANS,ans);
			}
		}
		cout<<n-ANS<<"\n";
	}
}