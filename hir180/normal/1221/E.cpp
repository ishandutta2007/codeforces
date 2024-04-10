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
int q;
int main(){
	cin >> q;
	while(q--){
		int a,b; cin >> a >> b;
		string s; cin >> s;
		bool bad = 0;
		int cnt = 0;
		int cur = 0,sum = 0,spe = 0;
		rep(i,s.size()){
			if(s[i] == 'X'){
				if(cur){
					if(b <= cur && cur < a) bad = 1;
					else if(cur >= a){
						if(cur >= 2*b) cnt++;
						if(cur >= 2*b) spe=cur;
						sum++;
					}
				}
				cur = 0;
			}
			else cur++;
		}
		if(cur){
			if(b <= cur && cur < a) bad = 1;
			else if(cur >= a){
				if(cur >= 2*b) cnt++;
				if(cur >= 2*b) spe=cur;
				sum++;
			}
		
		}
		if(bad || cnt >= 2) puts("NO");
		else{
			if(!spe) puts(sum%2==1?"YES":"NO");
			else{
			    for(int i=0;i<=spe-a;i++){
					int x = i, y = spe-a-i;
					if(x<b ||(a<=x&&x<b+b)){
						if(y<b ||(a<=y&&y<b+b)){
							int S = sum+(x>=b)+(y>=b);
							if(S%2==1){
								puts("YES"); goto nct;
							}
						}
					}
				}
				puts("NO"); nct:;
			}
		}
	}
}