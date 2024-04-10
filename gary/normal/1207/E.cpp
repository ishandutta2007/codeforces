//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define cc fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int RES=0;
int val;
int main(){
	cout<<"? ";
	rb(i,1,100) cout<<i<<" ";
	cout<<endl;cc;
	cin>>val;
	RES=val&(((1<<14)-1)-(1<<7)+1);
//	cout<<RES<<endl;
	cout<<"? ";
	int  tmp = 1<<7;
	int ADD=1<<7;
	rb(i,1,100) cout<<tmp+(i-1)*ADD<<" ";
	cout<<endl;cc;
	cin>>val;
	RES|=(val&((1<<7)-1));
	cout<<"! "<<RES<<endl;
	return 0;
}