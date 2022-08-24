#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,x1,x2,y1,y2;
long long squ(long long i){
	return i*1LL*i;
}
bool cmp(pair<long long,long long>i,pair<long long,long long>j){
	return i.second<j.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> x1 >> x2 >> y1 >> y2;
	long long xs,ys=0,ans=2e17,p,q;
	pair<long long,long long>a[n+1];
	for(long long i=1; i<=n ;i++){
		cin >> p >> q;
		a[i]=make_pair(squ(p-x1)+squ(q-x2),squ(p-y1)+squ(q-y2));
	}
	a[0]=make_pair(0,0);
	sort(a+1,a+n+1,cmp);
	for(long long i=0; i<=n ;i++){
		xs=0;
		ys=a[i].second;
		for(long long j=i+1; j<=n ;j++){
			xs=max(xs,a[j].first);
		}
		ans=min(ans,xs+ys);
	}
	cout << ans << endl;
}