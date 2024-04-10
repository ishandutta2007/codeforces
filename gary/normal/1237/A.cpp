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
int a[13845+10];
int main(){
	int n;
	cin>>n;
	int  cnt=0;
	rb(i,1,n) {cin>>a[i];if(abs(a[i])&1) cnt++;
	}
	cnt>>=1;
//	cout<<cnt<<endl;
	rb(i,1,n){
		if((abs(a[i])&1)==0){
			cout<<a[i]/2<<endl;
			continue;
		}double A=a[i];
		if(cnt){
			cnt--;
			int tmp=ceil(A/2);
			cout<<tmp<<endl;
		}	
		else{
			cout<<floor(A/2)<<endl;
		}
	}
	return 0;
}