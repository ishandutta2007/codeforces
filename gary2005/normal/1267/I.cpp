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
vector<int> v1,v2;
bool query(int A,int B){
	cout<<"? "<<A<<" "<<B<<endl;
	ff;
	char c;
	cin>>c;
	return c=='>';
}
void fixed1(){
	int IT=1;
	while(IT){
		if(!query(v1[IT],v1[IT-1])){
			swap(v1[IT],v1[IT-1]);
			IT--;
		}
		else
		break;
	}
}
void fixed2(){
	int IT=v2.size()-1;
	while(IT){
		if(!query(v2[IT],v2[IT-1])){
			swap(v2[IT],v2[IT-1]);
			IT--;
		}
		else break;
	}
}
void solve(){
	v1.clear();
	v2.clear();
	int n;
	cin>>n;
	rb(i,1,2){
		v1.PB(i);
	}
	fixed1();
	rb(i,3,n+1){
		v2.PB(i);
		fixed2();
	}
	rb(i,n+2,2*n){
		if(query(v1[0],v2[0])){
			//pop v2
			rb(i,1,n-2){
				v2[i-1]=v2[i];
			}
			v2[n-2]=i;
			fixed2();
		}
		else{
			//pop v1
			v1[0]=v1[1];
			v1[1]=i;
			fixed1();
		}
//		cout<<"--!\n";
	}
	query(v1[0],v2[0]);
	cout<<"!\n";
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}