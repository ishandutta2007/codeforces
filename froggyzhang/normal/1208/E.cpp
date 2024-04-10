#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,W,a[N],m;
ll s[N];
void Solve(){
	static int L[N],R[N];
	for(int i=1;i<=m;++i){
		L[i]=-W,R[i]=W+W+1;
	}
	static int st[N],top;
	st[top=1]=0;
	for(int i=1;i<=m;++i){
		while(top&&a[i]>=a[st[top]])--top;
		if(top)L[i]=st[top];
		st[++top]=i;
	}	
	st[top=1]=m+1;
	for(int i=m;i>=1;--i){
		while(top&&a[i]>a[st[top]])--top;
		if(top)R[i]=st[top];
		st[++top]=i;
	}
	int len=W-m+1;
	for(int i=1;i<=m;++i){
		int l=max(i,L[i]+len);
		int r=min(i+len-1,R[i]-1);
		if(l<=r)s[l]+=a[i],s[r+1]-=a[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>W;
	for(int i=1;i<=n;++i){
		cin>>m;
		for(int j=1;j<=m;++j){
			cin>>a[j];
		}
		a[m+1]=0;
		Solve();
	}
	for(int i=1;i<=W;++i){
		s[i]+=s[i-1];
		cout<<s[i]<<' ';
	}
	return 0;
}