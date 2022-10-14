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
map<int,mp> app;
int n;
int a[200000+233];
int id[200000+233];
bool cmp(int A,int B){
	return a[A]<a[B];
}
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	sort(id+1,id+1+n,cmp);
	sort(a+1,a+1+n);
	rb(i,1,n){
		rl(j,i-1,1){
			if(app.find(a[i]-a[j])!=app.end()){
				if(app[a[i]-a[j]].SEC!=j&&app[a[i]-a[j]].FIR!=j&&app[a[i]-a[j]].FIR!=i&&app[a[i]-a[j]].SEC!=i){
					printf("YES\n%d %d %d %d\n",id[app[a[i]-a[j]].SEC],id[j],id[i],id[app[a[i]-a[j]].FIR]);
					return 0;
				}
			}
			else{
				app[a[i]-a[j]]=II(j,i);
			}
		}
	}
	puts("NO");
	return 0;
}