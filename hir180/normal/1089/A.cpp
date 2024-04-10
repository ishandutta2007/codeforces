#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
int m;
bool dp[205][205][4][4][2];
int pre[205][205][4][4][2][5];
void hukugen(int a,int b,int c,int d,int e,int add,bool added){
	printf("%d:%d\n",c,d);
	vector<P>vec;
	while(a+b != 0){
		int na = pre[a][b][c][d][e][0];
		int nb = pre[a][b][c][d][e][1];
		int nc = pre[a][b][c][d][e][2];
		int nd = pre[a][b][c][d][e][3];
		int ne = pre[a][b][c][d][e][4];
		vec.pb(mp(a-na,b-nb));
		a = na; b = nb; c = nc; d = nd; e = ne;
	}
	if(added){
		for(int i=0;i<vec.size();i++){
			if(abs(vec[i].fi-vec[i].sc) == 2){
				vec[i].fi+=add;
				vec[i].sc+=add;
				break;
			}
		}
	}
	reverse(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++) printf("%d:%d%c",vec[i].fi,vec[i].sc,(i+1==vec.size()?'\n':' '));
//	puts("");
}
int main(){
	cin>>m;
	dp[0][0][0][0][0] = 1;
	for(int i=0;i<205;i++){
		for(int j=0;j<205;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					for(int x=0;x<2;x++){
						if(!dp[i][j][k][l][x]) continue;
						{
							for(int w=0;w<=23-10*(k+l==4);w++){
								dp[i+25-10*(k+l==4)][j+w][k+1][l][(x||(w==23-10*(k+l==4)))] = 1;
								pre[i+25-10*(k+l==4)][j+w][k+1][l][(x||(w==23-10*(k+l==4)))][0] = i;
								pre[i+25-10*(k+l==4)][j+w][k+1][l][(x||(w==23-10*(k+l==4)))][1] = j;
								pre[i+25-10*(k+l==4)][j+w][k+1][l][(x||(w==23-10*(k+l==4)))][2] = k;
								pre[i+25-10*(k+l==4)][j+w][k+1][l][(x||(w==23-10*(k+l==4)))][3] = l;
								pre[i+25-10*(k+l==4)][j+w][k+1][l][(x||(w==23-10*(k+l==4)))][4] = x;

							}
						}
						{
							for(int w=0;w<=23-10*(k+l==4);w++){
								dp[i+w][j+25-10*(k+l==4)][k][l+1][(x||(w==23-10*(k+l==4)))] = 1;
								pre[i+w][j+25-10*(k+l==4)][k][l+1][(x||(w==23-10*(k+l==4)))][0] = i;
								pre[i+w][j+25-10*(k+l==4)][k][l+1][(x||(w==23-10*(k+l==4)))][1] = j;
								pre[i+w][j+25-10*(k+l==4)][k][l+1][(x||(w==23-10*(k+l==4)))][2] = k;
								pre[i+w][j+25-10*(k+l==4)][k][l+1][(x||(w==23-10*(k+l==4)))][3] = l;
								pre[i+w][j+25-10*(k+l==4)][k][l+1][(x||(w==23-10*(k+l==4)))][4] = x;

							}
						}
					}
				}
			}
		}
	}
	while(m--){
		int aa,bb; cin>>aa>>bb;
		for(int dif=3;dif>=-3;dif--){
			for(int a=0;a<=3;a++){
				int b = a-dif;
				if(max(a,b) == 3 && a>=0 && b>=0 && a!=b){
					if(dp[aa][bb][a][b][0]){
						hukugen(aa,bb,a,b,0,0,false);
						goto nxt;
					}
					else{
						for(int gen=min(aa,bb);gen>=0;gen--){
							if(dp[aa-gen][bb-gen][a][b][1]){
								hukugen(aa-gen,bb-gen,a,b,1,gen,true);
								goto nxt;
							}
						}
					}
				}
			}
		}
		puts("Impossible");
		nxt:;
	}
}
/*
3:0
25:0 25:0 25:0
3:1
25:22 25:22 15:25 25:21
Impossible
0:3
0:25 0:25 0:25
3:0
25:11 28:26 25:13
3:2
25:17 0:25 25:22 15:25 15:11

3:0
25:0 25:0 25:0
3:1
25:22 25:22 15:25 25:21
Impossible
0:3
0:25 0:25 0:25
3:0
25:23 28:26 25:1
3:2
25:22 25:22 5:25 0:25 25:6
*/