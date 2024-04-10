#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct P{
	int x,y;
};
vector<P> ans;
void Do(int l,int r){
	if(l>r)return ;
	if(l==r){
		for(int i=1;i<=m/2;i++){
			ans.push_back({l,i});
			ans.push_back({l,m-i+1});
		}
		if(m%2)ans.push_back({l,m/2+1});
		return ;
	}
	for(int i=1,j=1,k=m;i<=m;i++,j++,k--){
		ans.push_back({l,j});
		ans.push_back({r,k});
	}
	Do(l+1,r-1);
}
int main(){
	cin>>n>>m;
	Do(1,n);
	for(P o:ans)cout<<o.x<<' '<<o.y<<'\n';
}