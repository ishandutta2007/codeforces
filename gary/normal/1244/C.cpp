/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	LL n,p,w,d;
	cin>>n>>p>>w>>d;
	LL y=0;
	rb(i,0,w){
		y=i;
		if(p-y*d<0) break;
		if((p-y*d)%w==0) break;
	}
	if((p-y*d)%w!=0) cout<<-1<<endl;
	else{
		LL x=(p-y*d)/w;
		LL z=n-y-x;
		if(z<0){
			cout<<-1<<endl;
		}
		else{
			cout<<x<<" "<<y<<" "<<z<<endl;
		}
	}
	return 0;
}