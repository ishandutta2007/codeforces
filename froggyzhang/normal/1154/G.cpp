#include<bits/stdc++.h>
using namespace std;
#define N 1000100
#define M 10001000
const int MX=1e7;
typedef long long ll;
int n,p1,p2,a[N],cnt[M],pos[M][2];
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(cnt[a[i]]==2)continue;
		pos[a[i]][cnt[a[i]]++]=i;
	}
	ans=1e18;
	for(int d=1;d<=MX;++d){
		vector<int> A;
		for(int i=d;i<=MX;i+=d){
			if(cnt[i]){
				for(int j=0;j<min(cnt[i],2);++j){
					A.push_back(pos[i][j]);	
				}
				if(A.size()>=2)break;
			}	
		}
		if(A.size()>1){
			ll w=1LL*a[A[0]]*a[A[1]]/d;
			if(w<ans){
				ans=w;
				p1=A[0],p2=A[1];
			}
		}
	}
	if(p1>p2)swap(p1,p2);
	cout<<p1<<' '<<p2<<'\n';
	return 0;
}