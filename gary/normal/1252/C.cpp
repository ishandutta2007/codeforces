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
#define POB pop_back
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int cnt[200000+10][4],k1,k2,k3,a[200000+10];
int main(){
	scanf("%d %d %d",&k1,&k2,&k3);
	rb(i,1,k1){
		int num;
		scanf("%d",&num);
		a[num]=1;
	}
	rb(i,1,k2){
		int num;
		scanf("%d",&num);
		a[num]=2;
	}
	rb(i,1,k3){
		int num;
		scanf("%d",&num);
		a[num]=3;
	}
	int n=k1+k2+k3;
	rb(i,1,n){
		rb(j,1,3){
			cnt[i][j]=cnt[i-1][j]+(a[i]==j);
		}
	} 
	int res=cnt[n][1]+cnt[n][2],tmp=0,l=0;
	rb(r,1,n){
		if(cnt[r][2]-cnt[r][1]<tmp){
			tmp=cnt[r][2]-cnt[r][1];
			l=r;
		}
		res=min(res,cnt[n][1]+cnt[n][2]-cnt[r][1]-cnt[r][2]+cnt[l][2]+cnt[l][3]+cnt[r][1]+cnt[r][3]-cnt[l][1]-cnt[l][3]);
//		cout<<r<<" "<<l<<" "<<cnt[n][1]+cnt[n][2]-cnt[l][1]-cnt[l][2]+cnt[l][2]+cnt[l][3]+cnt[r][1]+cnt[r][3]-cnt[l][1]-cnt[l][3]<<endl;
	}
	cout<<res<<endl;
	return 0;
}