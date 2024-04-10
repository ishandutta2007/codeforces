/**
 *    author:  gary
 *    created: 01.01.2022 20:32:12
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
int edge[65][65];
vector<vector<int> > mat;
int answer[300];
int is[1000000];
int gauss(){
    int cnt=0;
    rep(j,m){
        int x=-1;
        rb(i,cnt,(int)(mat.size())-1){
            if(mat[i][j]){
                x=i;
                break;
            }
        }
        if(x==-1) continue;
        is[cnt]=j;
        swap(mat[cnt],mat[x]);
        int tmp=mat[cnt][j];
        rep(k,m+1) mat[cnt][k]=tmp*mat[cnt][k]%3;
        rep(i,mat.size()){
            if(i!=cnt&&mat[i][j]){
                int tmp=mat[i][j];
                rep(k,m+1){
                    mat[i][k]-=tmp*mat[cnt][k]%3;
                    if(mat[i][k]<0) mat[i][k]+=3;
                }
            }
        }
        cnt++;
    }
    rep(i,mat.size()){
        if(i>=cnt&&mat[i][m]) return -1;
    }
    return cnt;
}
void solve(){
    mat.clear();
    cin>>n>>m;
    rb(i,1,n) rb(j,1,n) edge[i][j]=-1;
    rb(i,1,m){
        int u,v,c;
        cin>>u>>v>>c;
        edge[u][v]=edge[v][u]=i-1;
        if(c!=-1){
            vector<int> temp(m+1,0);
            temp[m]=c%3;
            temp[i-1]=1;
            mat.PB(temp);
        }
    }
    rb(i,1,n) rb(j,i+1,n) rb(k,j+1,n) if(edge[i][j]!=-1&&edge[j][k]!=-1&&edge[i][k]!=-1){
        vector<int> temp(m+1,0);
        temp[edge[i][j]]=temp[edge[j][k]]=temp[edge[i][k]]=1;
        mat.PB(temp);
    }
    int cnt=gauss();
    // cout<<"---"<<endl;
    if(cnt==-1){
        cout<<-1<<endl;
    }
    else{
        rep(i,m) answer[i]=0;
        rep(i,cnt) answer[is[i]]=mat[i][m];
        rep(i,m){
            if(answer[i]==0) answer[i]=3;
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }
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