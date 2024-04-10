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
LL ans;
int itself[200000+10],n;
map<pair<int,int> ,int> MP;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	rb(i,1,n){
		cin>>itself[i]; 
		ans+=itself[i];
	}
	int q;
	cin>>q;
	rb(i,1,q){
		int si,ti,ui;
		cin>>si>>ti>>ui;
		int OK=0;
		if(MP[II(si,ti)]){
			if(++itself[MP[II(si,ti)]]>0){
				ans++;
			}
			MP[II(si,ti)]=0;	
			
		}
		if(ui)
		{
			MP[II(si,ti)]=ui;
			if(itself[ui]>0){
				ans--;
			}
			itself[ui]--;
		}
		cout<<ans<<endl;
	}
	return 0;	
}