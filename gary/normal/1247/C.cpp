/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL n,p; 
int main(){
	cin>>n>>p;
	int res=-1;
	rb(i,1,60){
		if(n<=i*p){
			break;
		}
		int tmp=n-i*p;
		int cnt=0;
		while(tmp){
			cnt+=(tmp&1);
			tmp>>=1;
		}
		if(cnt<=i){
			LL cnt2=0;
			int tmp=n-i*p;
			int is=1;
			while(tmp){
				cnt2+=(tmp&1)*is;
				tmp>>=1;
				is<<=1;
			}
			if(cnt2>=i){
				res=i;
				break;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}