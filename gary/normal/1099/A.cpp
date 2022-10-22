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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int u1,d1,u2,d2;
int main(){
	int w,h;
	cin>>w>>h;
	cin>>u1>>d1>>u2>>d2;
	if(d1<d2) {
		swap(d1,d2);
		swap(u1,u2);
	}
	rl(i,h,1){
		w+=i;
		if(i==d1){
			w-=u1;
			w=max(0,w);
		}
		if(i==d2){
			w-=u2;
			w=max(0,w);
		}
//		cout<<w<<endl;
	}
	cout<<w<<endl;
	return 0;
}