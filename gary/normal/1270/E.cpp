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
int n;mp a[1000+10];int cnt[2][2];
int main(){
	scanf("%d",&n);
	rb(i,1,n)
		scanf("%d %d",&a[i].FIR,&a[i].SEC),a[i].FIR+=int(1e6+5),a[i].SEC+=int(1e6+5);
	vector<int> res;
	while(true){
		cnt[0][1]=cnt[1][0]=cnt[1][1]=cnt[0][0]=0;
		rb(i,1,n)
			cnt[a[i].FIR%2][a[i].SEC%2]++;
		if(cnt[0][0]+cnt[1][1]>0&&cnt[1][0]+cnt[0][1]>0){
			rb(i,1,n)
				if((a[i].FIR+a[i].SEC)&1){
					res.PB(i);
				}
			break;
		}
		if(cnt[1][1]+cnt[0][1]>0&&cnt[1][0]+cnt[0][0]>0){
			rb(i,1,n)
				if(a[i].FIR&1)
					res.PB(i);
			break;
		}
		rb(i,1,n)
			a[i].FIR>>=1,a[i].SEC>>=1;
	}
	cout<<res.size()<<endl;
	for(auto it:res){
		cout<<it<<" ";
	}
	return 0;
}