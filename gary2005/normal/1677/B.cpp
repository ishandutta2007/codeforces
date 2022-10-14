/**
 *    author:  gary
 *    created: 08.05.2022 22:28:00
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
char s[1000000+20];
int nx[1000000+20];
int ans[1000000+20];
int cf[1000000+20],ok[1000000+20];
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    int N=n*m;
    rb(i,0,N) ans[i]=cf[i]=ok[i]=0;
    nx[0]=-INF;
    rb(i,1,N){
        nx[i]=nx[i-1];
        if(s[i]=='1') {nx[i]=i;}
    }
    rb(i,1,N){
        if(s[i]=='1'){ok[i%m]=1;}
        if(!ok[i%m]){
            cf[i]++;
            cf[min(N+1,i+m)]--;
        }
    }
    rb(i,0,N) ok[i]=0;
    rb(i,1,N){
        if(i-nx[i]>=m){
            ok[i%m]++;
        }
        ans[i]+=ok[i%m];
        cf[i]+=cf[i-1];
        ans[i]+=cf[i];
        ans[i]+=n-(i+m-1)/m;
        if(i<m) ans[i]+=m-i;
        // cout<<ok[i%m]<<endl;
        printf("%d ",n+m-ans[i]);
    }
    puts("");
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}