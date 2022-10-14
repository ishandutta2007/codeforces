/*
It can be solved with 0 queries qwq in O(N) ??????
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
int n,k[505],id[505];
bool cmp(int A,int B){return k[A]<k[B];}
int main(){
	scanf("%d",&n);
	rb(i,1,n){int ki;scanf("%d",&ki);k[i]=n-1-ki;id[i]=i;}
	sort(id+1,id+1+n,cmp);
	sort(k+1,k+1+n);
	int pre=0,rest=-1,a,b,sum=0;
	rb(i,1,n){sum+=k[i];if(sum==(i-1)*i/2){if(pre!=i-1){if(rest<k[i]-k[pre+1]){a=i,b=pre+1,rest=k[i]-k[pre+1];}};pre=i;}}
	if(rest==-1) cout<<"! 0 0\n";
	else cout<<"! "<<id[a]<<' '<<id[b]<<"\n";
	return 0;
}