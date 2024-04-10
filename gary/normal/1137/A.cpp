/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[1001][1001];
map<int,int> M1[1001],M2[1001];
vector<int> col[1001],row[1001];
int main(){
	fastio;
	int n,m;
	cin>>n>>m;
	rb(i,1,n)
		rb(j,1,m)
			cin>>a[i][j],M1[i][a[i][j]]++,M2[j][a[i][j]]++;
	rb(i,1,n)
		for(map<int,int>:: IT ite=M1[i].begin();ite!=M1[i].end();ite++){
			row[i].PB(ite->FIR);
		}
	rb(j,1,m)
		for(map<int,int> :: IT ite=M2[j].begin();ite!=M2[j].end();ite++){
			col[j].PB(ite->FIR);
		}
	rb(i,1,n) sort(ALL(row[i]));
	rb(j,1,m) sort(ALL(col[j]));
	rb(i,1,n)
		rb(j,1,m){
			int one,two;
			one=lower_bound(ALL(row[i]),a[i][j])-row[i].begin();
			one++;
			two=lower_bound(ALL(col[j]),a[i][j])-col[j].begin();
			two++;
			int tmp=0;
			if(one<=two){
				tmp=two;
			}
			else{tmp=one;
				
			}
			tmp+=max(row[i].size()-one,col[j].size()-two);
			cout<<tmp<<" ";
			if(j==m){
				cout<<endl;
			}
		}
	return 0;
}