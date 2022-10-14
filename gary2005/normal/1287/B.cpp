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
map<string,int > M;
string record[2000];
int main(){
	int n;
	int k;
	cin>>n>>k;
	rb(i,1,n)
	{
		string s;
		cin>>s;
		record[i]=s;
		M[s]++;
	}
	int ans=0;
	rb(i,1,n){
		rb(j,i+1,n){
			int ok=1;
			string tmp="";
			rep(K,k){
				if(record[i][K]==record[j][K]){
					tmp+=record[i][K];
				}
				else{
					if(record[i][K]!='S'&&record[j][K]!='S'){
						tmp+='S'; 
					}
					if(record[i][K]!='E'&&record[j][K]!='E'){
						tmp+='E';
					}
					if(record[i][K]!='T'&&record[j][K]!='T'){
						tmp+='T';
					}
				}
			}
			if(ok)
			ans+=M[tmp];
		}
	}
	cout<<ans/3;
	return 0;
}