#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<int>divv[300005];
int n,k;
int u[300005];
vector<P>vec;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;i*j<=n;j++){
			divv[i*j].pb(i);
		}
	}
	for(int i=2;i<=n;i++){
		{
			int sz = divv[i].size();
			vec.pb(mp(-sz,i));
		}
	}
	u[1] = 1;
	SORT(vec);
	int cur = 0;
	for(int i=0;i<vec.size();i++){
		int num = vec[i].sc,pre = cur;
		for(int j=0;j<divv[num].size();j++) cur += u[divv[num][j]];
		for(int j=2;j*num<=n;j++) cur += u[j*num];
		if(cur > k){
			cur = pre;
			continue;
		}
		else u[vec[i].sc] = 1;
	}
	if(cur != k){
		puts("No");
	}
	else{
		puts("Yes");
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=u[i];
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++) if(u[i]) printf("%d ",i);
		puts("");
	}
}