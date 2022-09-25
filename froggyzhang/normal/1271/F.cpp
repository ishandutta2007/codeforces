#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,d[8],t1[3],t2[3],l[3],r[3];
void Solve(){
	for(int i=0;i<3;++i)cin>>t1[i];
	for(int i=0;i<3;++i)cin>>t2[i];
	for(int i=1;i<=7;++i)cin>>d[i];
	for(int i=0;i<3;++i){
		r[i]=t1[i];	
	}
	l[0]=d[1]+d[2]+d[3]+d[4]-t2[0];
	l[1]=d[1]+d[2]+d[5]+d[6]-t2[1];
	l[2]=d[1]+d[3]+d[5]+d[7]-t2[2];
	for(int i=0;i<3;++i){
		if(l[i]>r[i]){cout<<-1<<'\n';return;}	
	}
	for(int i=0;i<=d[2];++i){
		for(int j=0;j<=d[3];++j){
			for(int k=0;k<=d[5];++k){
				int L=0,R=d[1];
				L=max(L,l[0]-i-j-d[4]);
				R=min(R,r[0]-i-j);
				L=max(L,l[1]-i-k-d[6]);
				R=min(R,r[1]-i-k);
				L=max(L,l[2]-j-k-d[7]);
				R=min(R,r[2]-j-k);
				if(L<=R){
					cout<<L<<' '<<i<<' '<<j<<' '<<max(0,l[0]-i-j-L)<<' '<<k<<' '<<max(0,l[1]-i-k-L)<<' '<<max(0,l[2]-j-k-L)<<'\n';
					return;
				}	
			}
		}
	}
	cout<<-1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}