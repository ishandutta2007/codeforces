#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define tm arin
int n,m;
bool a[1201];
bool dp[1201][1201];
bool f[1201][2];
bool dp2[1201][2];
int prv[1201][2];
vector<pair<int,int> >god;
vector<int>god2;
int sz=0;
int tl[1201],tr[1201],tm[1201];
vector<int>ch[1201];
void build(int l,int r,int p){
	if(l>r) return;
	for(int i=l+2; i<r ;i+=3){
		if(dp[l][i] && dp[i+1][r]){
			build(l,i,p);
			build(i+1,r,p);
			return;
		}
	}
	//cout << "build " << l << ' ' << r << endl;
	++sz;
	if(p==0) god2.push_back(sz);
	ch[p].push_back(sz);
	tl[sz]=l,tr[sz]=r;
	if(r-l==2){
		tm[sz]=l+1;
		return;
	}
	for(int i=l+1; i<r ;i++){
		if(a[i]!=a[l]) continue;
		bool lok=(i==l+1 || dp[l+1][i-1]);
		bool rok=(r==i+1 || dp[i+1][r-1]);
		bool lgd=(i!=l+1 && a[l]!=a[l+1]);
		bool rgd=(r!=i+1 && a[r]!=a[r-1]);
		if(!lok || !rok) continue;
		if(!lgd && !rgd) continue;
		int id=sz;
		build(l+1,i-1,id);
		build(i+1,r-1,id);
		tm[id]=i;
		break;
	}
}
vector<int>bin[2][2];
vector<int>ans;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;m=6*n;
	for(int i=1; i<=3*n ;i++){
		int x;cin >> x;
		a[x]=true;
	}
	for(int i=m; i>=1 ;i--){
		for(int j=i+1; j<=m ;j++){
			f[j][0]=f[j][1]=false;
		}
		for(int j=i+1; j<=m ;j+=3){
			if(a[j]!=a[i]) continue;
			if(i+1==j) f[j][1]=true;
			else f[j][1]=dp[i+1][j-1];
		}
		//if(i==10) cout << f[14][1] << endl;
		for(int j=i+2; j<=m ;j+=3){
			if(a[j]!=a[i]) continue;
			for(int k=j-1; k>i ;k-=3){
				if(k==j-1){
					if(f[k][1]) dp[i][j]=true;
					continue;
				}
				if(!dp[k+1][j-1]) continue;
				if(f[k][1]){
					dp[i][j]=true;
				}
			}
		}
		for(int j=i+2; j<=m ;j+=3){
			for(int k=i+2; k<j ;k+=3){
				if(dp[i][k] && dp[k+1][j]) dp[i][j]=true;
			}
		}
	}
	/*for(int i=1; i<=m ;i++){
		for(int j=1; j<=m ;j++){
			cout << dp[i][j];
		}
		cout << endl;
	}*/
	//cout << dp[1][3] << ' ' << dp[4][9] << ' ' << dp[10][15] << ' ' << dp[16][24] << ' ' << dp[25][27] << ' ' << dp[28][30] << endl;
	//system("pause");
	dp2[0][0]=true;
	for(int i=3; i<=m ;i+=3){
		for(int j=i-2; j>=1 ;j-=3){
			if(dp[j][i]){
				if(!a[j]){
					if(dp2[j-1][0]){
						prv[i][0]=prv[i][1]=j;
						dp2[i][0]=dp2[i][1]=true;
					}
				}
				else{
					if(dp2[j-1][0]){
						prv[i][0]=j;
						dp2[i][0]=true;
					}
					if(dp2[j-1][1]){
						prv[i][1]=j;
						dp2[i][1]=true;
					}
				}
			}
		}
	}
	int cx=m,cy=1;
	while(cx>0){
		//cout << "haha " << cx << ' ' << cy << endl;
		if(!dp2[cx][cy]) while(true);
		int px=prv[cx][cy];
		god.push_back({px,cx});
		if(!a[px]) cy=0;
		cx=px-1;
	}
	for(auto c:god){
		build(c.fi,c.se,0);
	}
	for(int i=1; i<=sz ;i++){
		if(ch[i].empty()) continue;
		bool ok=false;
		for(auto c:ch[i]){
			if(a[tl[i]]!=a[tl[c]]) ok=true;
		}
		if(!ok) while(true);
	}
	for(auto c:god2){
		int u=a[tl[c]];
		int v=ch[c].size()>0;
		bin[u][v].push_back(c);
	}
	if(sz!=2*n) while(true);
	if(bin[0][0].empty() && bin[0][1].empty()) while(true);
	for(int i=1; i<=2*n ;i++){
		int u=(i+1)%2;
		int x;
		if(bin[u][1].empty()){
			if(bin[u][0].empty()){
				cout << "fuck " << endl;
				//while(true);
			}
			x=bin[u][0].back();bin[u][0].pop_back();
		}
		else{
			x=bin[u][1].back();bin[u][1].pop_back();
		}
		for(auto c:ch[x]){
			int u=a[tl[c]];
			int v=ch[c].size()>0;
			bin[u][v].push_back(c);
		}
		ans.push_back(x);
	}
	reverse(ans.begin(),ans.end());
	for(auto c:ans){
		cout << tl[c] << ' ' << tm[c] << ' ' << tr[c] << '\n';
	}
}