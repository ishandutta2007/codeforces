/**
 *    author:  gary
 *    created: 01.10.2021 13:19:43
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
int n,a[1000000+1],dist[1000000+1];
void solve(){
    int d;
    scanf("%d%d",&n,&d);
    rb(i,1,n) scanf("%d",&a[i]),dist[i]=INF;
    rb(i,1,n) if(a[i]==0) dist[i]=0;
    queue<int> q;
    rb(i,1,n) if(dist[i]==0) q.push(i);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(dist[(now+d+n-1)%n+1]==INF){
            dist[(now+d+n-1)%n+1]=dist[now]+1;
            q.push((now+d+n-1)%n+1);
        }
    }
    int tmp=*max_element(dist+1,dist+1+n);
    if(tmp==INF) tmp=-1;
    cout<<tmp<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}