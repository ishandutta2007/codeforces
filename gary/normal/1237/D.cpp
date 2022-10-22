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
int n,a[600000+10];
set<int> q; 
map<int,int> into;
int main(){
	cin>>n;
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,n+1,n+n+n)
		a[i]=a[i-n];
	int maxi=-1;
	rb(i,1,n){
		maxi=max(maxi,a[i]);
	}
	int OK=1;
	rb(i,1,n) if(a[i]*2<maxi) {
		OK=0;
		break;
	}
	if(OK){
		rb(i,1,n){
			printf("-1 ");
		}
		return 0;
	}
	int r=1;
	q.insert(-a[1]);
	into[a[1]]++;
	rb(i,1,n){
		if(r<i){
			into[a[i]]++;
			q.insert(-a[i]);
			r=i;
		}
//		if(i==16) cout<<-*q.begin()<<" "<<a[r+1]<<endl;
		while(a[r+1]*2>=-*q.begin()) {
			into[a[r+1]]++;
			q.insert(-a[++r]);
		}
		into[a[i]]--;
		if(!into[a[i]])
		q.erase(-a[i]);
		printf("%d ",r-i+1);
	}
	return 0;
}