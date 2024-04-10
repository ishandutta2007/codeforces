#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
ll ans;
const int g[7]={0,1,2,0,2,1,0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c;
	for(int i=0;i<7;++i){
		int ta=(a>=20?(a-10)/3:0);
		int tb=(b>=20?(b-10)/2:0);
		int tc=(c>=20?(c-10)/2:0);
		ll da=ta*7LL,db=tb*7LL,dc=tc*7LL;
		int ra=a-ta*3,rb=b-tb*2,rc=c-tc*2;
		for(int j=i;;++j,++da){
			if(g[j%7]==0){
				if(!ra)break;
				--ra;
			}
		}
		for(int j=i;;++j,++db){
			if(g[j%7]==1){
				if(!rb)break;
				--rb;
			}
		}
		for(int j=i;;++j,++dc){
			if(g[j%7]==2){
				if(!rc)break;
				--rc;
			}
		}
		ans=max(ans,min(da,min(db,dc)));	
	}
	cout<<ans<<'\n';
	return 0;
}