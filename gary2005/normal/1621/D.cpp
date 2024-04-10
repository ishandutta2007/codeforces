/**
 *    author:  gary
 *    created: 03.01.2022 22:14:13
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
const int MAXN=255;
int n,a[MAXN*2][MAXN*2];
int dist[MAXN*2][MAXN*2];
int walk[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void solve(){
    cin>>n;
    rb(i,1,2*n) rb(j,1,2*n) dist[i][j]=INF;
    rb(i,1,2*n) rb(j,1,2*n) cin>>a[i][j];
    LL answer=0;
    rb(i,n+1,2*n) rb(j,n+1,2*n) answer+=a[i][j];
    priority_queue<pair<int,mp>,vector<pair<int,mp> > ,greater<pair<int,mp> > > heap;
    rb(i,1,n) dist[n+1][i]=a[n+1][i],heap.push(II(a[n+1][i],II(n+1,i))),dist[2*n][i]=a[2*n][i],heap.push(II(a[2*n][i],II(n*2,i)));
    while(!heap.empty()){
        auto now=heap.top();
        int i,j;
        tie(i,j)=now.SEC;
        heap.pop();
        if(now.FIR!=dist[i][j]) continue;
        rep(x,4){
            int ni,nj;
            tie(ni,nj)=II(i+walk[x][0],j+walk[x][1]);
            if(ni>=n+1&&ni<=2*n&&nj>=1&&nj<=n&&dist[ni][nj]>dist[i][j]+a[ni][nj]){
                dist[ni][nj]=dist[i][j]+a[ni][nj];
                heap.push(II(dist[ni][nj],II(ni,nj)));
            }
        }
    }
    rb(i,1,n) dist[i][n+1]=a[i][n+1],heap.push(II(a[i][n+1],II(i,n+1))),dist[i][n*2]=a[i][n*2],heap.push(II(a[i][n*2],II(i,n*2)));
    while(!heap.empty()){
        auto now=heap.top();
        int i,j;
        tie(i,j)=now.SEC;
        heap.pop();
        if(now.FIR!=dist[i][j]) continue;
        rep(x,4){
            int ni,nj;
            tie(ni,nj)=II(i+walk[x][0],j+walk[x][1]);
            if(ni>=1&&ni<=n&&nj>=1+n&&nj<=2*n&&dist[ni][nj]>dist[i][j]+a[ni][nj]){
                dist[ni][nj]=dist[i][j]+a[ni][nj];
                heap.push(II(dist[ni][nj],II(ni,nj)));
            }
        }
    }
    int addi=INF;
    addi=min(addi,min(a[1][n+1],a[1][2*n]));
    addi=min(addi,min(a[n][n+1],a[n][2*n]));
    addi=min(addi,min(a[n+1][1],a[n+1][n]));
    addi=min(addi,min(a[2*n][1],a[2*n][n]));
    // rb(i,1+n,2*n) check_min(addi,dist[i][n]),check_min(addi,dist[n][i]),check_min(addi,dist[i][1]),check_min(addi,dist[1][i]);
    cout<<answer+addi<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}