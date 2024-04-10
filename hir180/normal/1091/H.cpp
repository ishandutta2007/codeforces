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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<int>pr,PR;
bool ok[200005];
int gr[200005];
bool used[200005];
bitset<200005>B[1024];
bitset<200005>igata;
int n,f;
int C ;
int main(){
	cin>>n>>f;
	for(int i=2;i<=200000;i++){
		if(ok[i]) continue;
		for(int j=2;i*j<=200000;j++) ok[i*j] = 1;
	}
	for(int i=2;i<=200000;i++) if(!ok[i]) pr.pb(i);
	vector<int>prr;
	for(int i=0;i<pr.size();i++){
		if(pr[i] > 500) break;
		for(int j=i;j<pr.size();j++){
			if(pr[i]*pr[j] > 200000) break;
			prr.pb(pr[i]*pr[j]);
		}
	}
	for(int i=0;i<prr.size();i++) pr.pb(prr[i]);
	for(int i=0;i<pr.size();i++) if(pr[i] != f) igata[pr[i]] = 1;
	//SORT(PR);
	gr[1] = 0;
	gr[2] = 0;
	B[0] |= (igata<<1);
	B[0] |= (igata<<2);
	for(int i=3;i<=200000;i++){
		for(int j=0;j<1024;j++){
			if(B[j][i] == 0){
				gr[i] = j;
				B[j] |= (igata<<i);
				break;
			}
		}
	}
	for(int i=0;i<n;i++){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		C ^= gr[b-a];
		C ^= gr[c-b];
	}
	if(C == 0){
		puts("Bob\nAlice");
	}
	else{
		puts("Alice\nBob");
	}
}