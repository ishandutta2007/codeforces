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
int mod_num[200000+10];
int a[200000+10];
int main(){
	int n,k;
	cin>>n>>k;
	rep(i,k) mod_num[i]=-INF;
	rb(i,1,n) {
		char c;
		cin>>c;
		a[i]=c^48;
	}
	rb(i,1,k){
		mod_num[i%k]=a[i];
	}
	int ok=1;
	rb(i,1,n){
		if(mod_num[i%k]<a[i]) ok=0;
		if(mod_num[i%k]>a[i]){
			break;
		}
	}
	if(ok){
		
	}
	else{
		rl(i,k,1){
			if(mod_num[i%k]!=9){
				mod_num[i%k]++;
				break;
			}
			else{
				mod_num[i%k]=0;
			}
		} 
	}
	cout<<n<<endl;
	rb(i,1,n){
		cout<<mod_num[i%k];
	}
	return 0;
}