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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[150005];
int cnt[150005];
bool in[150005];
int main(){
	scanf("%d",&n);
	repn(i,n) {scanf("%d",&a[i]);cnt[a[i]]++; in[a[i]]=1;}
	vector<P>vec;
	for(int i=1;i<=150000;){
		if(cnt[i-1] == 0 && cnt[i]){
			int ok = 0;
			int beg = i;
			while(i<=150000 && cnt[i]) {ok+=cnt[i]-1;i++;}
			int en = i-1;
			if(ok>=2){
				in[beg-1] = in[en+1] = 1;
			}
			else if(ok==0);
			else { vec.pb(P(beg-1,en+1)); }
		}
		else i++;
	}
	for(int i=0;i<vec.size();i++){
		if(vec[i].fi <= 0){
			in[vec[i].sc] = 1;
		}
		else if(!in[vec[i].fi]) in[vec[i].fi] = 1;
		else in[vec[i].sc] = 1;
	}
	int ans = 0;
	for(int i=1;i<=150004;i++) ans+=in[i];
	cout<<ans<<endl;
}