#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int A,B,n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>A>>B;
	n=A+B;
	int ans=0;
	for(int l=1,r=0;l<=n;l=r+1){
		int t=n/l;
		r=n/t;
		int la=(A+t)/(t+1),ra=A/t;
		int lb=(B+t)/(t+1),rb=B/t;
		if(ra>=la&&rb>=lb)ans+=max(0,min(r,ra+rb)-max(l,la+lb)+1);
	}
	cout<<ans<<'\n';
	return 0;
}