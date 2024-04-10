/**
 *    author:  gary
 *    created: 10.10.2021 19:36:25
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+1;
int n,a[MAXN];
bool c[MAXN];
int main(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    rb(i,1,n){
        char c_;
        cin>>c_;
        c[i]=(c_=='R');
    }
    // puts("");
    int cnt=0;
    rb(i,2,n) cnt+=c[i]==c[i-1];
    sort(a+1,a+1+n);
    int l=cnt,r=cnt+1;
    int pw;
    rb(i,1,n){
        int j=i;
        while(j<n&&c[j+1]==c[i]) ++j;
        printf("%d %c\n",a[r++],"LR"[c[i]]);
        if(i==1) pw=c[i];
        rb(k,i+1,j){
            pw^=1;
            printf("%d %c\n",a[l--],"LR"[pw]);
        }
        i=j;
    }
    return 0;
}