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
int q,n;
vector<int>edge[500005];
char ch[500005];
bool win;
int main(){
	cin>>q;
	int x = 0;
	int qq = q;
	while(qq--){
		x++;
		scanf("%d",&n); 
		rep(i,n) edge[i].clear();
		rep(i,n-1){
			int a,b; scanf("%d%d",&a,&b); a--; b--;
			edge[a].pb(b);
			edge[b].pb(a);
		}
		scanf("%s",&ch); 
		
		if(n < 3){
		    if(q!=INF) puts("Draw"); continue;
		}
		win = 0;
		for(int i=0;i<n;i++){
			if(edge[i].size() >= 4){
				win = 1;
			}
		}
		if(win){
		    if(q!=INF) puts("White");
			continue;
		}
		//-------
		
		//---------
		// |    (|)
		vector<int>vi;
		for(int i=0;i<n;i++){
			if(edge[i].size() == 3){
				vi.pb(i);
				int a = edge[i][0];
				int b = edge[i][1];
				int c = edge[i][2];
				int flag = 0;
				flag += (edge[a].size()>=2);
				flag += (edge[b].size()>=2);
				flag += (edge[c].size()>=2);
				if(flag >= 2) win = 1;
			}
		}
		if(vi.size() >= 3){
		    if(q!=INF) puts("White");
			continue;
		}
		if(win){
		    if(q!=INF) puts("White");
		    continue;
		}
		if(vi.size() == 0){
			//line graph
			int cnt = 0;
			for(int i=0;i<n;i++){
				if(edge[i].size() == 2 && ch[i] == 'W'){
					if(n>=4) win = 1;
				}
				else if(ch[i] == 'W') cnt++;
			}
			if(n == 3){
			    int C = 0;
			    rep(i,n) C += ch[i] == 'W';
			    if(C == 2) puts("White"); else puts("Draw");
			}
			else if(win || (cnt==2 && n%2 == 1)){
			    if(q!=INF) puts("White");
			}
			else{
			    if(q!=INF) puts("Draw");
			}
			continue;
		}
		else if(vi.size() == 2){
			//---- + ||
			for(int i=0;i<n;i++){
				if(ch[i] == 'W'){
					win = 1;
				}
			}
			if(win || n%2 == 1){
			    if(q!=INF) puts("White");
			}
			else{
			    if(q!=INF) puts("Draw");
			}
			continue;
		}
		else{
		    bool OK = 0;
			for(int i=0;i<n;i++){
				if(ch[i] == 'W'){
					if(edge[i].size() == 1){
						int to = edge[i][0];
						if(edge[to].size() == 2){
							win = win; OK = 1;
						}
						else win = 1;
					}
					else win = 1;
				}
			}
			if(win || (OK && n%2 == 0)){
			    if(q!=INF) puts("White");
			}
			else{
			    if(q!=INF) puts("Draw");
			}
			continue;
		}
	}
}