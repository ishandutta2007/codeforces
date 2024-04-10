/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#pragma GCC optimize(2)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int a[100000+20];
int main(){
//	fastio;
	int t;
	R(t);
	while(t--){
		int n,l;
		R2(n,l);
		rb(i,1,n) scanf("%d",&a[i]);
		a[0]=0;
		a[n+1]=l;
		int L,R;
		L=0,R=n+1;
		double nt1=1.0*a[1]/1.0,nt2=1.0*(l-a[n])/1.0;
		int speed1=1,speed2=1;
		double rest=0.0;
		while(1){
			if(nt1<nt2){
				nt2-=nt1;
				rest+=nt1;
				speed1++;
				nt1=(double)(a[L+2]-a[L+1])/(double)(speed1);
				L++;
				if(L==R-1){
					double dis=nt2*speed2;
					rest+=dis/(double)(speed1+speed2);
					break;
				}
			}
			else{
				if(nt1>nt2){
					nt1-=nt2;
					rest+=nt2;
					speed2++;
					nt2=(double)(a[R-1]-a[R-2])/(double)speed2;
					R--;
					if(L==R-1){
						double dis=nt1*speed1;
						rest+=dis/(double)(speed1+speed2);
						break;
					}
				}
				else{
					if(L==R-2){
						rest+=nt1;
						break;
					}
					rest+=nt1;
					speed1++;
					speed2++;
					R--;
					L++;
					nt1=(double)(a[L+1]-a[L])/(double)(speed1);
					nt2=(double)(a[R]-a[R-1])/(double)(speed2);
					if(L==R-1)
					{
						rest+=(double)(a[R]-a[L])/(double)(speed1+speed2);
						break;
					}
				}
			}
		}
		printf("%.10f\n",rest);
	}
	return 0;
}