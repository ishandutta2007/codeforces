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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int one[1000],two[1000];
int main(){
	int t;
	cin>>t;
	while(t--){
	int n,k1,k2;
	cin>>n>>k1>>k2;
	rb(i,1,k1)
		cin>>one[i];
	rb(i,1,k2)
		cin>>two[i];
	sort(one+1,one+1+k1);
	sort(two+1,two+1+k2);
	if(two[k2]>one[k1]){
		cout<<"NO";
	}
	else{
		cout<<"YES";
	}	
	cout<<endl;
	}
	
	return 0;
}