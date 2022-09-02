#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
//#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
int ans[100005][5],nxt = 0;
void calc(vector<int>vi){//cout<<nxt<<endl;
	if(vi.size() <= 4){
		if(vi.size() == 3){
		    for(int i=0;i<vi.size();i++) ans[nxt][i] = ans[nxt+1][i] = vi[i];
		    nxt+=2;
		}
		else{
		       ans[nxt][0]=vi[0];ans[nxt][1]=vi[1];ans[nxt][2]=vi[2];nxt++;
		       ans[nxt][0]=vi[0];ans[nxt][1]=vi[1];ans[nxt][2]=vi[3];nxt++;
		       ans[nxt][0]=vi[0];ans[nxt][1]=vi[2];ans[nxt][2]=vi[3];nxt++;
		       ans[nxt][0]=vi[1];ans[nxt][1]=vi[2];ans[nxt][2]=vi[3];nxt++;
		}
		return;
	}
	if(vi.size()%2 == 1){
		int x = 0,y = 1;
		while(1){
			x = (x+vi.size()-1)%vi.size();
			y = (y+1)%vi.size();
			vector<int>vec;
			if(x == y){
				ans[nxt][0] = ans[nxt+1][0] = vi[0];
				ans[nxt][1] = ans[nxt+1][1] = vi[1];
				ans[nxt][2] = ans[nxt+1][2] = vi[x];
			}
			else{
				ans[nxt][0] = ans[nxt+1][0] = vi[0];
				ans[nxt][1] = ans[nxt+1][1] = vi[y];
				ans[nxt][2] = ans[nxt+1][2] = vi[1];
				ans[nxt][3] = ans[nxt+1][3] = vi[x];
			}
			nxt+=2;
			if(x == y) break;
		}
		reverse(vi.begin(),vi.end());
		vi.pop_back();vi.pop_back();
		reverse(vi.begin(),vi.end());
		calc(vi); return;
	}
	else{
		int x = 0,y = 1;
		while(1){
			x = (x+vi.size()-1)%vi.size();
			y = (y+1)%vi.size();
			vector<int>vec;
			if(y+1 == x){
				ans[nxt][0]=vi[0];ans[nxt][1]=vi[1];ans[nxt][2]=vi[x];nxt++;
				ans[nxt][0]=vi[0];ans[nxt][1]=vi[1];ans[nxt][2]=vi[y];nxt++;
				ans[nxt][0]=vi[0];ans[nxt][1]=vi[y];ans[nxt][2]=vi[1];ans[nxt][3]=vi[x];nxt++;
			}
			else{
				ans[nxt][0] = ans[nxt+1][0] = vi[0];
				ans[nxt][1] = ans[nxt+1][1] = vi[y];
				ans[nxt][2] = ans[nxt+1][2] = vi[1];
				ans[nxt][3] = ans[nxt+1][3] = vi[x];
				nxt+=2;
			}
			if(y+1 == x) break;
		}
		reverse(vi.begin(),vi.end());
		vi.pop_back();vi.pop_back();
		reverse(vi.begin(),vi.end());
		calc(vi); return;
	}
}
int main(){
	cin>>n;
	vector<int>vec;
	for(int i=1;i<=n;i++){
		vec.pb(i);
	}memset(ans,-1,sizeof(ans));
	calc(vec);
	for(int i=0;i<100005;i++){
		if(ans[i][0] == -1){
			cout<<i<<endl;
			break;
		}
	}
	//int cnt[305][305];
	for(int i=0;i<100005;i++){
		if(ans[i][0] == -1) return 0;
		int b;
		for(int j=0;j<5;j++){
			if(ans[i][j] == -1) {cout<<j<<" "; break;}
		}
		for(int j=0;j<b;j++){
		   // cnt[ans[i][j]][ans[i][(j+1)%b]]++;
		   // cnt[ans[i][(j+1)%b]][ans[i][j]]++;
		}
		for(int j=0;j<5;j++){
			if(ans[i][j] == -1) {cout<<endl;break;}
			else cout<<ans[i][j]<<" ";
		}
	}
//	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(cnt[i][j]!=2)cout<<i<<" "<<j<<endl;
}