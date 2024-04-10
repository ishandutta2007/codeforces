/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
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
int res[1000000+10];
int main(){
	LL n,k;
	cin>>n>>k;
	if(k<(n*(n+1))/2){
		puts("-1");
	}
	else{
		k-=(n*(n+1))/2;
		rb(i,1,n) res[i]=i;
		int tot=n-1,p2=n,p1=1;
		while(k>=tot&&p2>p1){
			k-=tot;
			tot-=2;
			swap(res[p2],res[p1]);
			p2--;
			p1++;
		}
		if(p2>p1){
			if(k<tot){
				swap(res[p2],res[p2-k]);
			}
		}
		LL res1=0;
		rb(i,1,n) res1+=max(i,res[i]);
		cout<<res1<<endl;
		rb(i,1,n) printf("%d ",i);cout<<endl;
		rb(i,1,n) printf("%d ",res[i]);
	}
	return 0;
}