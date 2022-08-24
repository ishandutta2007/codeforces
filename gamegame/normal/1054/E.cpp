#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
struct act{
	int sx,sy,ex,ey;
};
string s[301][301],t[301][301];
string p[301][301];
int cnt[301][2],cnt2[301][2];
vector<act>sm,tm;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> s[i][j];
			//p[i][j]=s[i][j];
			for(int k=0; k<s[i][j].size()/2 ;k++) swap(s[i][j][k],s[i][j][s[i][j].size()-k-1]);
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> t[i][j];
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			for(int k=0; k<s[i][j].size() ;k++){
				if(s[i][j][k]=='0' && j==1){
					int nx=i-1,ny=j;
					if(nx==0) nx=2;
					cnt[nx][j-1]++;
					act newi={i,j,nx,ny};
					sm.push_back(newi);
				}
				else if(s[i][j][k]=='1' && j==2){
					int nx=i-1,ny=j;
					if(nx==0) nx=2;
					cnt[nx][j-1]++;
					act newi={i,j,nx,ny};
					sm.push_back(newi);
				}
				else{
					int cur=s[i][j][k]-'0';
					int nx=i,ny=cur+1;
					cnt[nx][cur]++;
					act newi={i,j,nx,ny};
					sm.push_back(newi);
				}
			}
		}
	}
	for(int i=2; i<=n ;i++){
		for(int j=0; j<cnt[i][0] ;j++){
			act newi={i,1,1,1};
			sm.push_back(newi);
		}
		for(int j=0; j<cnt[i][1] ;j++){
			act newi={i,2,1,2};
			sm.push_back(newi);
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			for(int k=0; k<t[i][j].size() ;k++){
				if(t[i][j][k]=='0' && j==1){
					int nx=i-1,ny=j;
					if(nx==0) nx=2;
					cnt2[nx][0]++;
					act newi={i,j,nx,ny};
					tm.push_back(newi);
				}
				else if(t[i][j][k]=='1' && j==2){
					int nx=i-1,ny=j;
					if(nx==0) nx=2;
					cnt2[nx][1]++;
					act newi={i,j,nx,ny};
					tm.push_back(newi);
				}
				else{
					int cur=t[i][j][k]-'0';
					int nx=i,ny=cur+1;
					cnt2[nx][cur]++;
					act newi={i,j,nx,ny};
					tm.push_back(newi);
				}
			}
		}
	}
	for(int i=2; i<=n ;i++){
		for(int j=0; j<cnt2[i][0] ;j++){
			act newi={i,1,1,1};
			tm.push_back(newi);
		}
		for(int j=0; j<cnt2[i][1] ;j++){
			act newi={i,2,1,2};
			tm.push_back(newi);
		}
	}
	cout << sm.size()+tm.size() << endl;
	for(auto cur:sm){
		cout << cur.sx << ' ' << cur.sy << ' ' << cur.ex << ' ' << cur.ey << '\n';
		/*system("pause");
		p[cur.ex][cur.ey]=p[cur.sx][cur.sy].back()+p[cur.ex][cur.ey];
		p[cur.sx][cur.sy].pop_back();
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=m ;j++)
				cout << p[i][j] << ' ';
			cout << endl;
		}*/
			
	}
	reverse(tm.begin(),tm.end());
	for(auto cur:tm){
		cout << cur.ex << ' ' << cur.ey << ' ' << cur.sx << ' ' << cur.sy << '\n';
		/*system("pause");
		p[cur.ex][cur.ey]=p[cur.sx][cur.sy].back()+p[cur.ex][cur.ey];
		p[cur.sx][cur.sy].pop_back();
		for(int i=1; i<=n ;i++){
			for(int j=1; j<=m ;j++)
				cout << p[i][j] << ' ';
			cout << endl;
		}*/
	}
}