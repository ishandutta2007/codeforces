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
bool check(int x){
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int main(){
	int r,c;
	cin>>r>>c;
	if(r==1&&c==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(r==1){
		rb(i,1,c){
			cout<<1+i<<" ";
		}
		return 0;
	}
	if(c==1){
		rb(i,1,r){
			cout<<1+i<<endl;
		}
		return 0;
	}
	rb(i,1,r){
		rb(j,1,c){
			cout<<(i+c)*j<<" ";
		}
		cout<<endl;
	}
	return 0;
}