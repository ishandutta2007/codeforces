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
int n,q[100000+10],p[100000+10],used[100000+10];
void solve()
{
	int OK=1;
	scanf("%d",&n);
	rb(i,1,n) used[i]=0;
	rb(i,1,n) scanf("%d",&q[i]);
	p[1]=q[1];
	int mini=1;
	if(q[1]==1) mini++;
	used[p[1]]=1;
	rb(i,2,n){
		if(q[i]!=q[i-1]){
			p[i]=q[i];
			used[p[i]]=1;
		}
		else{
			while(used[mini]){
				mini++;
			}
			if(mini>q[i]){
				OK=0;
				break;
			}
			p[i]=mini;
			used[mini]=1;
			mini++;
			while(used[mini]){
				mini++;
			}
		}
	}
	rb(i,1,n) {
		if(!used[i]) OK=0;
	}
	if(!OK){
		puts("-1");
		return ;
	}
	rb(i,1,n) printf("%d ",p[i]);puts("");
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}