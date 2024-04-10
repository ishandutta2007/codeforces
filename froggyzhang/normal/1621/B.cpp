#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int inf=0x3f3f3f3f3f3f3f3fll;
int n;
void Solve(){
	cin>>n;
	int L=inf+1,R=-inf,lmn=inf,rmn=inf,tmn=inf;
	for(int i=1;i<=n;++i){
		int l,r,c;
		cin>>l>>r>>c;
		if(l<L)L=l,lmn=tmn=inf;
		if(r>R)R=r,rmn=tmn=inf;
		if(l==L)lmn=min(lmn,c);
		if(r==R)rmn=min(rmn,c);
		if(l==L&&R==r)tmn=min(tmn,c);
		cout<<min(lmn+rmn,tmn)<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}