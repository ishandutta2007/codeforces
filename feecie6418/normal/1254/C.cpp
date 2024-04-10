#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
typedef vector<int> ve;
const int mod=998244353;
int nxt,n;
ll area[1005];
int main(){
	cin>>n;
	nxt=2;
	for(int i=3;i<=n;i++){
		cout<<2<<' '<<1<<' '<<nxt<<' '<<i<<endl;
		int res;
		cin>>res;
		if(res==-1)nxt=i;
	}
	ll mxar=0;
	int pos=0;
	for(int i=2;i<=n;i++){
		if(i==nxt)continue;
		cout<<1<<' '<<1<<' '<<nxt<<' '<<i<<endl;
		cin>>area[i];
		if(area[i]>mxar)mxar=area[i],pos=i;
	}
	vector<int> dn,up;
	for(int i=2;i<=n;i++){
		if(i==nxt||i==pos)continue;
		cout<<2<<' '<<1<<' '<<pos<<' '<<i<<endl;
		int res;
		cin>>res;
		if(res==-1)dn.push_back(i);
		else up.push_back(i);
	}
	sort(dn.begin(),dn.end(),[](int x,int y){return area[x]<area[y];});
	sort(up.begin(),up.end(),[](int x,int y){return area[x]>area[y];});
	cout<<"0 1 "<<nxt<<' ';
	for(auto i:dn)cout<<i<<' ';
	cout<<pos<<' ';
	for(auto i:up)cout<<i<<' ';
	cout<<endl;
}