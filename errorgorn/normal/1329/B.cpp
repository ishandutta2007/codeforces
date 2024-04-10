#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

ll d,MOD;

ll cnt[50]; //how many with this many bits in front
ll memo[50];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
		
	int TC;
	cin>>TC;
	while (TC--){
		memset(cnt,0,sizeof(cnt));
		memset(memo,0,sizeof(memo));
		
		cin>>d>>MOD;
		
		for (int x=1;x<50;x++){
			if ((1LL<<x)<=d){
				cnt[x]=(1LL<<(x-1));
			}
			else{
				cnt[x]=d-(1LL<<(x-1))+1;
				break;
			}
		}
		
		for (int x=0;x<50;x++){
			cnt[x]%=MOD;
			//cout<<cnt[x]<<" ";
		}
		//cout<<endl;
		
		ll ans=0;
		
		memo[0]=1;
		for (int x=1;x<33;x++){
			for (int y=0;y<x;y++){
				memo[x]+=cnt[x]*memo[y];
				memo[x]%=MOD;
			}
			ans+=memo[x];
			ans%=MOD;
		}
		
		cout<<ans<<endl;
	}
	
}