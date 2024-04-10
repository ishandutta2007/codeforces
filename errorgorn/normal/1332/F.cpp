#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

const ll MOD=998244353;
ll n;
vector<ll> al[300005];
ll color[300005];
ll uncolor[300005];
ll disconnect[300005];

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


void dfs(int i,int p){
	color[i]=1;
	uncolor[i]=1;
	disconnect[i]=1;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
		color[i]*=(color[it]+uncolor[it]*2+disconnect[it]+1*disconnect[it]);
		uncolor[i]*=(color[it]*2+uncolor[it]*2+disconnect[it]+2*disconnect[it]);
		disconnect[i]*=(color[it]+uncolor[it]+disconnect[it]);
		
		//MOD pls
		color[i]%=MOD;
		uncolor[i]%=MOD;
		disconnect[i]%=MOD;
		
	}
	color[i]=(color[i]-disconnect[i]+MOD)%MOD;
	uncolor[i]=(uncolor[i]-disconnect[i]+MOD)%MOD;
	
	
	//cout<<i<<" "<<color[i]<<" "<<uncolor[i]<<" "<<disconnect[i]<<endl;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>n;
	int a,b;
	for (int x=1;x<n;x++){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	dfs(1,-1);
	
	cout<<(color[1]+uncolor[1]+disconnect[1]-1+MOD)%MOD<<endl;
}