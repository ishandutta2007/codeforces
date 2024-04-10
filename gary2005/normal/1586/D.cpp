/**
 *    author:  gary
 *    created: 17.10.2021 19:02:44
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int p[101];
int main(){
    int n;
    cin>>n;
    rb(i,1,n-1){
        // <= i ?
        cout<<"? ";
        rb(j,1,n-1) printf("1 ");
        printf("%d ",i+1);
        cout<<endl;
        int x;
        ff;
        cin>>x;
        if(x==0){
            p[n]=n-i+1;
            break;
        }
    }
    if(p[n]==0) p[n]=1;
    rb(i,1,p[n]-1){
        cout<<"? ";
        rb(j,1,n-1) printf("%d ",i+1);
        printf("%d ",1);
        cout<<endl;
        int x;
        ff;
        cin>>x;
        p[x]=p[n]-i;
    }
    rb(i,1,n-p[n]){
        cout<<"? ";
        rb(j,1,n-1) printf("%d ",1);
        printf("%d ",i+1);
        cout<<endl;
        int x;
        ff;
        cin>>x;
        p[x]=p[n]+i;
    }
    cout<<"! ";
    rb(i,1,n){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    ff;
    return 0;
}