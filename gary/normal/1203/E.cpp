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
int a[150000+10];
int res;
int main(){
	int n;
	
	cin>>n;
	res=n;
	rb(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[1]!=1) a[1]--;
	rb(i,2,n){
		if(a[i]==a[i-1]){
			a[i]++;
		}
		else{
			if(a[i]<a[i-1]){
				a[i]=a[i-1];
				res--;
			}
			else{
				if(a[i]-1>a[i-1]) a[i]--;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}