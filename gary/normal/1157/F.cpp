/**
 *    author:  gary
 *    created: 25.09.2021 14:44:08
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
int N,cnt[200001];
vector<int> id[200000+1];
int main(){
    cin>>N;
    rb(i,1,N){
        int ai;
        scanf("%d",&ai);
        id[ai].PB(ai);
        cnt[ai]++;
    }
    N=2e5;
    vector<mp> seg;
    int c=0,pre=1;
    rb(i,1,N){
        if(cnt[i]<2){
            if(c){
                seg.PB(II(pre,i-1));
            }
            c=0;
        }
        else{
            c++;
            if(c==1){
                pre=i;
            }
        }
    }
    if(c){
        seg.PB(II(pre,N));
    }
    if(seg.empty()){
        rb(i,1,N-1){
            if(cnt[i]==1&&cnt[i+1]==1){
                cout<<2<<endl;
                cout<<id[i][0]<<" "<<id[i+1][0]<<endl;
                return 0;
            }
        }
        rb(i,1,N){
            if(cnt[i]==1){
                cout<<1<<endl;
                cout<<id[i][0]<<endl;
                return 0;
            }
        }
    }
    vector<int> answer;
    for(auto it:seg){
        int l=it.FIR,r=it.SEC;
        if(cnt[l-1]==1) l--;
        if(cnt[r+1]==1) r++;
        int save=cnt[r];
        vector<int> nownow;
        rb(i,l+1,r-1) cnt[i]--;
        rb(i,l,r) cnt[i]--;
        rb(i,l,r){
            nownow.PB(i);
            while(cnt[i]>=1){
                nownow.PB(i);
                cnt[i]--;
            }
        }
        rl(i,r-1,l+1){
            nownow.PB(i);
        }
        if(nownow.size()>answer.size()) answer=nownow;
        cnt[r]=save;
    }
    cout<<answer.size()<<endl;
    for(auto it:answer) printf("%d ",it);
    return 0;
}