
#include<bits/stdc++.h>
using namespace std;
int a[3005],n,b[3005];
vector<int> ans;
void Do(int p){
	if(p==1)return ;
	reverse(a+1,a+p+1),ans.push_back(p);
}
void Reverse(int l,int r){
	if(l==r)return ;
	if(l%2==1){
		Do(r),Do(r-l+1),Do(r);
	}
	else {
		Do(r+1),Do(r-l+1),Do(r+1),Do(l+1),Do(r+1),Do(r-1);
	}
}
vector<int> Try(){
	for(int i=n;i>=1;i--){
		int j=i;
		while(a[j]!=i)j--;
		Reverse(j,i);
	}
	for(int i=1;i<=n;i++)assert(a[i]==i);
	vector<int> p;
	for(int i:ans){
		if(p.size()&&i==p.back())p.pop_back();
		else p.push_back(i);
	}
	return p;
}
void Solve(){
	cin>>n;
	bool flag=0;
//	for(int i=1;i<=n;i++)a[i]=i;
//	for(int i=1;i<=100000;i++){
//		int x=rand()%n+1,y=rand()%n+1;
//		while(x%2!=y%2)x=rand()%n+1,y=rand()%n+1;
//		swap(a[x],a[y]);
//	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=1;i<=n;i++)if(a[i]%2!=i%2)flag=1;
	if(flag)return puts("-1"),void();
	ans.clear();
	vector<int> p=Try();
	if(p.size()<=2.5*n){
		cout<<p.size()<<'\n';
		for(int i:p)cout<<i<<' ';
		puts("");
		return ;
	}
	ans.clear();
	for(int i=1;i<=n;i++)a[i]=b[i];
	Do(n);
	p=Try();
	if(p.size()<=2.5*n){
		cout<<p.size()<<'\n';
		for(int i:p)cout<<i<<' ';
		puts("");
		return ;
	}
	assert(0);
}
int main(){
	srand(time(0));
	int t;
	cin>>t;
	while(t--)Solve();
}