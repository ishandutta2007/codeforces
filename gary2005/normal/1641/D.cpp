/**
 *    author:  gary
 *    created: 23.02.2022 18:08:48
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
int n,m;
const int MAXN=1e5+1;
int a[MAXN][5],l[MAXN],r[MAXN],w[MAXN],d[MAXN];
int ord[MAXN*5],mx[MAXN*5];
int main(){
    int ti=clock();
    cin>>n>>m;
    int answer=2e9+10;
    map<int,int> M;
    rb(i,1,n) {rep(j,m) {scanf("%d",&a[i][j]);};scanf("%d",&w[i]);}
    SRAND;
    rb(i,1,n) rep(j,m) M[a[i][j]]=1;
    while(m<5){
        rb(i,1,n){
            int T=random(1000000000)+1;
            while(M[T]) T=random(1000000000)+1;
            M[T]=1;
            a[i][m]=T;
        }
        m++;
    }
    int cnt=0;
    for(auto ite=M.begin();ite!=M.end();ite++) ite->second=++cnt;
    rb(i,1,n) rep(j,m) a[i][j]=M[a[i][j]];
    rb(i,1,cnt) ord[i]=i;
    rb(T,1,INF){
        if(clock()-ti>2930){
            break;
        }
        shuffle(ord+1,ord+1+cnt,rng);
        memset(mx,63,sizeof(mx));
        rb(i,1,n){
            l[i]=min(min(min(ord[a[i][0]],ord[a[i][1]]),min(ord[a[i][2]],ord[a[i][3]])),ord[a[i][4]]);
            r[i]=max(max(max(ord[a[i][0]],ord[a[i][1]]),max(ord[a[i][2]],ord[a[i][3]])),ord[a[i][4]]);
            mx[r[i]]=min(mx[r[i]],w[i]);
        }
        rb(j,1,cnt) mx[j]=min(mx[j-1],mx[j]);
        rb(i,1,n){
            if(mx[l[i]-1]!=INF){
                check_min(answer,mx[l[i]-1]+w[i]);
            }
        }
    }
    if(answer>2e9) answer=-1;
    cout<<answer<<endl;
    return 0;
}