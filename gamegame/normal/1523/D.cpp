#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n,m,p;
ll a[N];
int bit[N];
int dp[65536];
int pop[65536];
ll anss=0;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> p;
	for(int i=1; i<=n ;i++){
		for(int j=0; j<m ;j++){
			char c;cin >> c;
			if(c=='1') a[i]|=(1LL<<j);
		}
	}
	int ans=0;
	for(int i=1; i<=30 ;i++){
		int x=rand()%32768*32768+rand()%32768;
		x=x%n+1;
		int q=0;
		for(int j=0; j<m ;j++){
			if(a[x]&(1LL<<j)){
				bit[q++]=j;
			}
		}
		for(int i=0; i<(1<<q) ;i++){
			dp[i]=0;
		}
		for(int j=1; j<=n ;j++){
			int mk=0;
			for(int k=0; k<q ;k++){
				if(a[j]&(1LL<<bit[k])) mk|=1<<k;
			}
			dp[mk]++;
		}
		for(int j=0; j<q ;j++){
			for(int k=0; k<(1<<q) ;k++){
				if(k&(1<<j)) continue;
				dp[k]+=dp[k|(1<<j)];
			}
		}
		for(int j=1; j<(1<<q) ;j++){
			pop[j]=pop[j^(j&-j)]+1;
			if(dp[j]>=(n+1)/2 && pop[j]>ans){
				ans=pop[j];anss=0;
				for(int k=0; k<q ;k++){
					if(j&(1<<k)) anss|=(1LL<<bit[k]);
				}
			}
		}
	}
	for(int i=0; i<m ;i++){
		if((anss>>i)&1) cout << "1";
		else cout << "0";
	}
}