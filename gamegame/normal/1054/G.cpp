#include<iostream>
using namespace std;
typedef unsigned long long ll;
int n,m;
ll mix[2000][33];
ll ex[32];
int cnt[2000];
bool dead[2000];
ll sec[2000][33];
int mem[2000];
bool vis[2000];
int par[2000];
void solve(){
	cin >> n >> m;
	for(int i=0; i<n ;i++){
		par[i]=-1;
		dead[i]=false;
		for(int j=0; j<32 ;j++) mix[i][j]=ex[j]=0;
		for(int j=0; j<=((n-1)>>6) ;j++) mix[i][j]=ex[j]=-1;
		mix[i][n>>6]=((ll)1<<(n&63))-1;
		ex[n>>6]=((ll)1<<(n&63))-1;
	}
	for(int i=0; i<m ;i++){
		vis[i]=false;
		char c;
		for(int j=0; j<32 ;j++) sec[i][j]=0;
		for(int j=0; j<=((n-1)>>6) ;j++) sec[i][j]=0;
		mem[i]=0;
		for(int j=0; j<n ;j++){
			cin >> c;
			sec[i][j>>6]|=(ll)(c-'0')<<(j&63);
			mem[i]+=c-'0';
		}
		for(int j=0; j<n ;j++){
			if(sec[i][j>>6]&((ll)1<<(j&63))){
				for(int k=0; k<=((n-1)>>6) ;k++) mix[j][k]&=sec[i][k];
			}
		}
		//cout << "Group: " << i << ' ' << sec[i][0] << ' ' << mem[i] << endl;
	}
	for(int i=0; i<n ;i++){//compute cnt
		cnt[i]=0;
		for(int j=0; j<n ;j++) cnt[i]+=((mix[i][j>>6]&((ll)1<<(j&63)))!=0);
		if(mix[i][i>>6]&((ll)1<<(i&63))) continue;
		else cout << "SEVENHEAD\n";
		//cout << "Bff: " << i << ' ' << mix[i][0] << ' ' << cnt[i] << endl;
	}
	for(int i=1; i<n ;i++){
		for(int j=0; j<m ;j++){
			if(vis[j] || mem[j]>1) continue;
			//Appears here M times
			vis[j]=true;
			int bad;
			for(int k=0; k<=((n-1)>>6) ;k++){
				if(sec[j][k]==0) continue;
				//appears here M times
				for(int l=0; l<64 ;l++){
					if(sec[j][k]&((ll)1<<l)){
						bad=(k<<6)|l;
						break;
					}
				}
				break;
			}
			//cout << "Lonely L found!: in group " << j << ", he is " << bad << '\n';
			//bad is only member of group j
			//recompute mix of bad
			for(int k=0; k<=((n-1)>>6) ;k++) mix[bad][k]=ex[k];
			for(int k=0; k<m ;k++){
				if(vis[k]) continue;
				if(sec[k][bad>>6]&((ll)1<<(bad&63))){
					for(int l=0; l<=((n-1)>>6) ;l++) mix[bad][l]&=sec[k][l];
				}
			}
			cnt[bad]=0;
			for(int k=0; k<n ;k++) cnt[bad]+=((mix[bad][k>>6]&((ll)1<<(k&63)))!=0);
		}
		bool done=false;
		for(int j=0; j<n ;j++){
			if(dead[j] || cnt[j]==1) continue;
			done=true;
			//N times here
			dead[j]=true;
			mix[j][j>>6]^=((ll)1<<(j&63));//remove self from friend list
			int bro=-327;
			ex[j>>6]^=((ll)1<<(j&63));
			for(int k=0; k<=((n-1)>>6) ;k++){
				if(mix[j][k]==0) continue;
				for(int l=0; l<64 ;l++){
					if(mix[j][k]&((ll)1<<l)){
						bro=(k<<6)|l;
						break;
					}
				}
				break;
			}
			par[j]=bro;
			for(int k=0; k<n ;k++){
				if(dead[k]) continue;
				if(mix[k][j>>6]&((ll)1<<(j&63))){
					cnt[k]--;
					mix[k][j>>6]^=(ll)1<<(j&63);
				}
			}
			for(int k=0; k<m ;k++){
				if(vis[k]) continue;
				if(sec[k][j>>6]&((ll)1<<(j&63))){
					mem[k]--;
					sec[k][j>>6]^=(ll)1<<(j&63);
				}
			}
			break;
		}
		if(!done){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	for(int i=0; i<n ;i++){
		if(par[i]!=-1) cout << i+1 << ' ' << par[i]+1 << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) solve();
}