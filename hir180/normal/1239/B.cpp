#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
const ll mod = 1000000007;
int n;
string s;
int rui[300005];
vector<int>pos[2],V[600005];
int mnn[300005][20];
int x[300005];
int calc(int a,int y){
	if(a > y) return 1000000;
	int L = y-a+1;
	return min(mnn[a][x[L]], mnn[y-(1<<x[L])+1][x[L]]);
}
//please stop creating problems.
int main(){
	repn(i,300000) rep(j,19){
		if((1<<j) < i && i <= (2<<j)){
			x[i] = j; break;
		}
	}
	cin >> n >> s;
	rep(i,n){
		rui[i+1] = rui[i] + (s[i]=='('?1:-1);
	}
	if(rui[n] != 0){
		puts("0");
		puts("1 1");
		return 0;
	}
	int mn = 100000;
	repn(i,n) mn = min(mn,rui[i]);
	repn(i,n) V[rui[i]+300000].pb(i);
	repn(i,n) pos[ (s[i-1]=='(') ].pb(i);
	repn(i,n) mnn[i][0] = rui[i];
	rep(j,19) repn(i,n){
		if(i+(1<<j) > n) mnn[i][j+1] = mnn[i][j];
		else mnn[i][j+1] = min(mnn[i][j],mnn[i+(1<<j)][j]);
	}
	int ans = V[mn+300000].size();
	P sw = P(1,1);
	repn(i,n){
		if(s[i-1] == '('){
			for(int val=mn;val>=mn-2;val--){
				int x = lower_bound(pos[0].begin(),pos[0].end(),i)-pos[0].begin();
				int y = pos[0].size(); y--;
				int lb = x, ub = y+1;
				while(ub-lb > 1){
					int mid = (lb+ub)/2;
					int M = pos[0][mid]-1;
					int nwmn = min(mn,calc(i,M)-2);
					if(nwmn >= val) lb = mid;
					else ub = mid;
				}
				if(lb < 0 || lb >= pos[0].size()) continue;
				int M = pos[0][lb]-1;
				int nwmn = min(mn,calc(i,M)-2);
				if(nwmn != val || i > M) continue;
				int p = upper_bound(V[val+300000].begin(),V[val+300000].end(),i-1)-V[val+300000].begin();
				int q = upper_bound(V[val+300000+2].begin(),V[val+300000+2].end(),M)-lower_bound(V[val+300000+2].begin(),V[val+300000+2].end(),i);
				int r = upper_bound(V[val+300000].begin(),V[val+300000].end(),1000000)-upper_bound(V[val+300000].begin(),V[val+300000].end(),M);
				if(ans < p+q+r){
					ans = p+q+r;
					sw = P(i,M+1);
				}
			}
		}
		else{
			for(int val=mn;val<=mn+2;val++){
				int x = lower_bound(pos[1].begin(),pos[1].end(),i)-pos[1].begin();
				int y = pos[1].size(); y--;
				int lb = x-1,ub = y;
				while(ub-lb > 1){
					int mid = (lb+ub)/2;
					int M = pos[1][mid]-1;
					int A = calc(1,i-1);
					int B = calc(i,M)+2;
					int C = calc(M+1,n);
					int nwmn = min(A,min(B,C));
					if(nwmn >= val) ub = mid;
					else lb = mid;
				}
				if(ub < 0) continue;
				int M = pos[1][ub]-1;
				int A = calc(1,i-1);
				int B = calc(i,M)+2;
				int C = calc(M+1,n);
				int nwmn = min(A,min(B,C));
				if(nwmn != val || i > M) continue;
				int p = upper_bound(V[val+300000].begin(),V[val+300000].end(),i-1)-V[val+300000].begin();
				int q = upper_bound(V[val+300000-2].begin(),V[val+300000-2].end(),M)-lower_bound(V[val+300000-2].begin(),V[val+300000-2].end(),i);
				int r = upper_bound(V[val+300000].begin(),V[val+300000].end(),1000000)-upper_bound(V[val+300000].begin(),V[val+300000].end(),M);
				if(ans < p+q+r){
					ans = p+q+r;
					sw = P(i,M+1);
				}
			}
		}
	}
	cout << ans << endl;
	cout << sw.fi << " " << sw.sc << endl;
}