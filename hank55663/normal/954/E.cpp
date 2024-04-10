#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
	int a[2000005];
	int t[2000005];
int main(){
	int n,T;
	scanf("%d %d",&n,&T);

	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&t[i]);
	LL totp=0,totn=0;
	for(int i=0;i<n;i++){
		if(t[i]>T){
			totp+=(LL)(t[i]-T)*a[i];
		}
		else{
			totn+=(LL)(T-t[i])*a[i];
		}
	}
	double ans=0;
	if(totp>totn){
		
		vector<pii> v;
		for(int i=0;i<n;i++){
			if(t[i]>T){
				v.pb(mp(t[i]-T,a[i]));
			}
			else
				ans+=a[i];
		}
		sort(v.begin(),v.end());
		LL num=0;
		for(auto it:v){
			if(num+(LL)it.x*it.y<=totn)
				ans+=it.y,num+=(LL)it.x*it.y;
			else{
				ans+=(double)(totn-num)/it.x;
				num=totn;
			}
		}
	}
	else{

		vector<pii> v;
		for(int i=0;i<n;i++){
			if(t[i]<T){
				v.pb(mp(T-t[i],a[i]));
			}
			else
				ans+=a[i];
		}
		sort(v.begin(),v.end());
		LL num=0;
		for(auto it:v){
			if(num+(LL)it.x*it.y<=totp)
				ans+=it.y,num+=(LL)it.x*it.y;
			else{
				ans+=(double)(totp-num)/it.x;
				num=totp;
			}
		}
	}
	printf("%.12lf\n",ans);
}
/*
BC
ACC
AABC
CC
ABC
AACC*/