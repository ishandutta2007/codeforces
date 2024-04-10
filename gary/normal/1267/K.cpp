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
vector<int> fs;
LL fact[22];
int tot[22];
void solve(LL k){
	fs.clear();
	rep(i,22) tot[i]=0;
	rb(i,2,22){
		fs.PB(k%i);
		tot[k%i]++;
		k/=i;
		if(k==0) break;
	}
	sort(ALL(fs));
	int n=fs.size();
	int SZ=fs.size();
	int minus=0;
	LL res=1;
	rl(i,SZ-1,0){
		int it=fs[i];
		int array=n-max(it,1)+1;
		array-=minus++;
		res*=array;
	}
	rb(i,0,21){
		res/=fact[tot[i]];
	}
	if(tot[0]){
		fs.clear();
		tot[0]--;
		rep(i,22){
			rep(j,tot[i]){
				fs.PB(i);
			}
		}
		LL tmp=1;
		sort(ALL(fs));
	int n=fs.size();
	int SZ=fs.size();
	int minus=0;
	rl(i,SZ-1,0){
		int it=fs[i];
		int array=n-max(it,1)+1;
		array-=minus++;
		tmp*=array;
	}
	rb(i,0,21){
		tmp/=fact[tot[i]];
	}
	res-=tmp;
	}
	cout<<res-1<<endl;
}
int main(){
	int t;
	cin>>t;
	fact[0]=1;
	rb(i,1,21){
		fact[i]=fact[i-1]*i;
	}
	while(t--){
		LL k;
		scanf("%I64d",&k);
		solve(k);
	}
	return 0;
}