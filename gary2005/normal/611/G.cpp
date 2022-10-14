/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
struct vec{
	LL x,y;
	vec(){x=y=0;}
	vec(LL xx,LL yy){x=xx,y=yy;}
	LL operator * (vec oth){
		return x*oth.y-oth.x*y;
	} 	
	vec operator - (vec oth){
		return vec(x-oth.x,y-oth.y);
	}
	vec operator + (vec oth){
		return vec(x+oth.x,y+oth.y);
	}
	vec operator * (int t){
		return vec(x*t,y*t);
	}
};
const int MAXN=5e5+2;
int n;
vec a[MAXN+MAXN+MAXN];
int l[MAXN],r[MAXN];
typedef __int128 bigint;
struct bigvec{
	bigint x,y;
	bigvec(){x=y=bigint(0);}
	bigvec(bigint xx,bigint yy){x=xx,y=yy;}
	bigvec (vec v){x=bigint(v.x),y=bigint(v.y);}
	bigint operator * (vec oth){
		return x*int(oth.y)-y*int(oth.x);
	}
	bigvec operator + (bigvec oth){
		return bigvec(x+oth.x,y+oth.y);
	}
	bigvec operator - (bigvec oth){
		return bigvec(x-oth.x,y-oth.y);
	}
	bigvec operator * (int t){
		return bigvec(x*t,y*t);
	}
};
int main(){
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d",&n);
	rb(i,1,n) scanf("%lld%lld",&a[i].x,&a[i].y);
	rb(i,1,n) a[i+n+n]=a[i+n]=a[i];
	LL tot=0;
	rb(i,3,n) tot+=(a[i]-a[1])*(a[i-1]-a[1]);
	l[1]=n;
	LL alr=0;
	while(true){
		l[1]--;
		alr+=(a[l[1]+1]-a[1])*(a[l[1]]-a[1]);
		if(alr>tot-alr){
			alr-=(a[l[1]+1]-a[1])*(a[l[1]]-a[1]);
			l[1]++;
			break;
		}
	}
	rb(i,2,n){
		l[i]=l[i-1];
		alr+=(a[i-1]-a[i])*(a[l[i]]-a[i]);
		while(alr>tot-alr){
			alr-=(a[l[i]+1]-a[i])*(a[l[i]]-a[i]);
			l[i]++;
		}
	}
	rb(i,1,n){
		r[i]=l[i]-1;
		while(r[i]<i+n) r[i]+=n;
	}
	bigint save=0;
	bigvec save2;
	bigint sum=0;
	bigvec vecsum;
	int cnt=0;
	bigint rest=bigint(tot)*(1ll*n*(n-3)/2);
	bigint minu=bigint(0);
	rb(i,l[1],n){
		++cnt;
		save=save+(bigint(a[i+1]*a[i])*cnt);
		sum=sum+bigint(a[i+1]*a[i]);
		save2=save2+(bigvec(a[i+1]-a[i])*cnt);
		vecsum=vecsum+bigvec(a[i+1]-a[i]);
	}
	
	minu=minu+save-save2*a[1];
	rb(i,2,n){
		save=save+(bigint(a[i]*a[i-1])*(n+i-l[i-1]));
		sum=sum+bigint(a[i]*a[i-1]);
		save2=save2+(bigvec(a[i]-a[i-1])*(n+i-l[i-1]));
		vecsum=vecsum+(bigvec(a[i]-a[i-1]));
		for(int j=l[i-1];j<=l[i]-1;++j){
			save=save-sum;
			sum=sum-bigint(a[j+1]*a[j]);
			save2=save2-vecsum;
			vecsum=vecsum-bigvec(a[j+1]-a[j]);
		}
		minu=minu+save-save2*a[i];
	}
	cnt=0;
	save=0;
	sum=0;
	save2=vec();
	vecsum=vec();
	rl(i,r[n],n+n+1){
		++cnt;
		save=save+(bigint(a[i]*a[i-1])*cnt);
		sum=sum+bigint(a[i]*a[i-1]);
		save2=save2+(bigvec(a[i]-a[i-1])*cnt);
		vecsum=vecsum+bigvec(a[i]-a[i-1]);
	}
	minu=minu+save-save2*a[n];
	rl(i,n-1,1){
		save=save+(bigint(a[i+1]*a[i])*(r[i+1]-(n+i)));
		sum=sum+bigint(a[i+1]*a[i]);
		save2=save2+(bigvec(a[i+1]-a[i])*(r[i+1]-(n+i)));
		vecsum=vecsum+(bigvec(a[i+1]-a[i]));
		for(int j=r[i+1];j>=r[i]+1;--j){
			save=save-sum;
			save2=save2-vecsum;
			sum=sum-bigint(a[j]*a[j-1]);
			vecsum=vecsum-bigvec(a[j]-a[j-1]);
		}
		minu=minu+save-save2*a[i];
	}
	rest-=minu;
	rest%=(int)(1e9+7);
	vector<int> v;
	while(rest){
		v.PB(rest%10);
		rest/=10;
	}
	if(v.empty()) v.PB(0);
	reverse(ALL(v));
	for(auto it:v){
		cout<<it;
	}
	return 0;
}

/*

4
1 1
1 0
0 0
0 1


5
2 4
2 7
5 7
5 4
3 -2

4
1000000000 1000000000
1000000000 -1000000000
-1000000000 -1000000000
-1000000000 1000000000

*/