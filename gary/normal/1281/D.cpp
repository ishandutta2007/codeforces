/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
11.
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int r,c;
char cou[100][100];

void solve(){
	cin>>r>>c;
	rb(i,1,r)
		rb(j,1,c){
			cin>>cou[i][j];
		}
	int OK=0,OK2=0;
	rb(i,1,r)
		rb(j,1,c) OK=OK|bool(cou[i][j]=='A'),OK2=OK2|bool(cou[i][j]=='P');
	if(!OK2){
		puts("0");
		return;
	}
	if(!OK){
		puts("MORTAL");
		return;
	}
	OK=1;
	rb(i,1,c){
		if(cou[1][i]!='A') OK=0;
	}
	if(OK){
		puts("1");return;
	}
	OK=1;
	rb(i,1,c){
		if(cou[r][i]!='A') OK=0;
	}
	if(OK){
		puts("1");return;
	}
	OK=1;
	rb(i,1,r){
		if(cou[i][1]!='A') OK=0;
	}
	if(OK){
		puts("1");return;
	}
	OK=1;
	rb(i,1,r){
		if(cou[i][c]!='A') OK=0;
	}
	if(OK){
		puts("1");return;
	}
	if(r==1&&c==1){
		puts("2");
		return;
	}
	rb(i,1,r){
		int OK=1;
		rb(j,1,c){
			if(cou[i][j]!='A') OK=0;
		}
		if(OK){
			cout<<"2"<<endl;
			return;
		}
	}
	rb(i,1,c){
		int OK=1;
		rb(j,1,r){
			if(cou[j][i]!='A') OK=0;
		}
		if(OK){
			cout<<"2"<<endl;
			return;
		}
	}
	if(cou[r][c]=='A'||cou[1][c]=='A'||cou[r][1]=='A'||cou[1][1]=='A'){
		puts("2");
		return;
	}
	OK=1;
	rb(i,1,c){
		if(cou[1][i]=='A') OK=0;
	}
	rb(i,1,c){
		if(cou[r][i]=='A') OK=0;
	}
	rb(i,1,r){
		if(cou[i][1]=='A') OK=0;
	}
	rb(i,1,r){
		if(cou[i][c]=='A') OK=0;
	}
	if(!OK){
		puts("3");return;
	}
	else{ 	
		puts("4");
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}