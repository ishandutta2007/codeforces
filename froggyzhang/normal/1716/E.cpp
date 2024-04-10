#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1<<18],Q;
struct Data{
	ll mx,sl,sr,sum;
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		c.mx=max(max(a.mx,b.mx),a.sr+b.sl);
		c.sl=max(a.sl,a.sum+b.sl);
		c.sr=max(b.sr,b.sum+a.sr);
		c.sum=a.sum+b.sum;
		return c;
	}
};
vector<Data> Solve(int L,int R){
	if(L==R){
		vector<Data> tmp;
		tmp.push_back({max(0,a[L]),max(0,a[L]),max(0,a[L]),a[L]});
		return tmp;
	}
	int mid=(L+R)>>1;
	auto tl=Solve(L,mid);
	auto tr=Solve(mid+1,R);
	vector<Data> A;
	for(int i=0;i<(int)tl.size();++i){
		A.push_back(tl[i]+tr[i]);
	}
	for(int i=0;i<(int)tl.size();++i){
		A.push_back(tr[i]+tl[i]);
	}
	return A;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<1<<n;++i){
		cin>>a[i];
	}
	auto A=Solve(0,(1<<n)-1);
	int u=0;
	cin>>Q;
	while(Q--){
		int k;
		cin>>k;
		u^=1<<k;
		cout<<A[u].mx<<'\n';
	}
	return 0;
}
//pvpv